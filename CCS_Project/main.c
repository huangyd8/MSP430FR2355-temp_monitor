#include <msp430.h> 
#include <main.h>
#include <ssd1306_lcd.h>
#include <font_table.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <DS18B20.h>


//global vars
volatile unsigned char TXcounter=0; //how many bytes
volatile unsigned char *TXpointer;
volatile unsigned char RXData;
volatile float temperature;



int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    __bis_SR_register(GIE);   // Enter LPM0 w/ interrupt

    I2C_INIT();
    UART_INIT();


    __delay_cycles(100);

    I2C_SET_ADDRESS(0x3c);
    LCD_Init();                         //init the LCD
    LCD_Clear(0x00);                    //set all pixels 0x00

    char data[5];

    while(1){
        temperature=get_data_DS18B20();

        sprintf(data,"%.1f",temperature);

        sendUARTBytes(data);
        sprintf(data,"T:%.1f°C",temperature);


        LCD_DrawStringKern(0, 3, data);
        __delay_cycles(1000000);
    }

}

void sendUARTBytes(volatile const char* string){
    uint8_t count = 0;


    while (string[count] != '\0')
    {
        UCA0TXBUF = string[count];
        while (UCA0STATW & UCBUSY);
        count++;
    }
    UCA0TXBUF='\n';
}

void I2C_INIT(){
    P1SEL0 |= BIT2 | BIT3;                                  // I2C pins

    UCB0CTLW0 =UCSWRST;                                     //enter config mode
    UCB0CTLW0 |= UCMST + UCMODE_3 + UCSYNC + UCSSEL_2 ;     // smclk master sync  i2c
    UCB0BRW = 0x08;                                         //1000/8 = 125 khz
    UCB0CTLW0 &= ~UCSWRST;                                  //exit config mode

    I2C_SET_ADDRESS( 0x3c);                                 //set slave address
    UCB0IE = UCTXIE0 +UCRXIE0;                              // interrupt tx


}

void UART_INIT(){
    P1SEL0 |= BIT6 | BIT7;                                  //UART pins

    UCA0CTLW0 |= UCSWRST;                                   // Put eUSCI in reset
    UCA0CTLW0 |= UCSSEL_1;
    UCA0BR0 = 6;                                            // INT(32768/4800)
    UCA0BR1 = 0x00;
    UCA0MCTLW = 0xEE00;
    UCA0CTLW0 &= ~UCSWRST;                                  // Initialize eUSCI
    UCA0IE |= UCRXIE;                                       // Enable USCI_A0 RX interrupt
}

void I2C_SET_ADDRESS(unsigned char address){

    UCB0I2CSA = address;                                    //set slave address

}


void sendI2CBytes(volatile unsigned char *data,volatile unsigned char lenght ){
    TXcounter=lenght;                                      //how many bytes do you wish to send
    TXpointer = data;
    UCB0CTL1 |= UCTR | UCTXSTT;                            // send start condition
    while(TXcounter!=0);
}






#pragma vector = USCI_B0_VECTOR
__interrupt void USCIB0_ISR(void){
    switch(__even_in_range(UCB0IV, USCI_I2C_UCBIT9IFG))
    {
    case USCI_NONE: break;                 // Vector 0: USCI_NONE : No interrupts
    case USCI_I2C_UCALIFG: break;          // Vector 2: ALIFG : Arbitration lost
    case USCI_I2C_UCNACKIFG:break;         // Vector 4: NACKIFG : Not acknowledgment
    case USCI_I2C_UCSTTIFG: break;         // Vector 6: STTIFG  : Start condition received
    case USCI_I2C_UCSTPIFG: break;         // Vector 8: STPIFG  : Stop condition received
    case USCI_I2C_UCRXIFG3: break;         // Vector 10: RXIFG3 : Slave 3 Data received
    case USCI_I2C_UCTXIFG3: break;         // Vector 14: TXIFG3 : Slave 3 Transmit buffer empty
    case USCI_I2C_UCRXIFG2: break;         // Vector 16: RXIFG2 : Slave 2 Data received
    case USCI_I2C_UCTXIFG2: break;         // Vector 18: TXIFG2 : Slave 2 Transmit buffer empty
    case USCI_I2C_UCRXIFG1: break;         // Vector 20: RXIFG1 : Slave 1 Data received
    case USCI_I2C_UCTXIFG1: break;         // Vector 22: TXIFG1 : Slave 1 Transmit buffer empty
    case USCI_I2C_UCRXIFG0: break;         // Vector 24: RXIFG0 : Data received
    case USCI_I2C_UCTXIFG0: {

        if(TXcounter){                     //how many bits to tx

            UCB0TXBUF= *TXpointer;
            TXpointer++;
            TXcounter--;
        }
        else UCB0CTL1 |= UCTXSTP;

        break;

    }                                      // Vector 26: TXIFG0 : Transmit buffer empty
    case USCI_I2C_UCBCNTIFG:break;         // Vector 28: BCNTIFG : Byte counter zero
    case USCI_I2C_UCCLTOIFG:break;         // Vector 30:  UCCLTOIFG : Clock low time-out
    case USCI_I2C_UCBIT9IFG:break;         // Vector 32: 9th bit : Nineth bit position
    default: break;
    }
}

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void) {
  switch(__even_in_range(UCA1IV,USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG: break;
    case USCI_UART_UCTXIFG: {
        break;}
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
    default: break;

  }
}
