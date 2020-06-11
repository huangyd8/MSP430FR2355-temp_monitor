/*
 * DS18B20.c
 *
 *  Created on: May 27, 2020
 *      Author: kyme32
 */

#include <msp430.h>
#include <DS18B20.h>

float get_data_DS18B20(){
    float temper=0;

    reset_DS18B20();
    send_DS18B20(0xcc);   //send CCH,Skip ROM command
    send_DS18B20(0x44);
    __delay_cycles(100);

    reset_DS18B20();
    send_DS18B20(0xcc);   //send CCH,Skip ROM command
    send_DS18B20(0xbe);

    temper = read_DS18B20();

    return(temper);
}

void reset_DS18B20(void)
{
    WIRE_DIR |=WIRE_PIN;
    WIRE_OUT &= ~WIRE_PIN;
    __delay_cycles(500);
    WIRE_OUT |=WIRE_PIN;
    WIRE_DIR &= ~WIRE_PIN;
    __delay_cycles(500);
}

void send_DS18B20(char data)
{
    char i;

    for(i=8;i>0;i--)
    {
        WIRE_DIR |=WIRE_PIN;
        WIRE_OUT &= ~WIRE_PIN;
        __delay_cycles(2);
        if(data & 0x01)
        {
            WIRE_OUT |= WIRE_PIN;
        }
        __delay_cycles(60);
        WIRE_OUT |= WIRE_PIN;
        WIRE_DIR &= ~WIRE_PIN;
        data >>=1;
    }
}

float read_DS18B20()
{
    char i;
    unsigned int data_raw=0;
    float temper;

    for(i=16;i>0;i--)
    {
        WIRE_DIR |= WIRE_PIN;
        WIRE_OUT &= ~WIRE_PIN;
        __delay_cycles(2);
        WIRE_OUT |=WIRE_PIN;
        WIRE_DIR &= ~WIRE_PIN;
        __delay_cycles(8);

        if(WIRE_IN & WIRE_PIN)
        {
            data_raw |=0x8000;
        }
        data_raw>>=1;
        __delay_cycles(120);
    }
    temper=(float)data_raw/8;
    return (temper);
}
