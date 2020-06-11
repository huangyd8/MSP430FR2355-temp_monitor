/*
 * main.h
 *
 *  Created on: May 25, 2020
 *      Author: kyme32
 */

void sendI2CBytes(volatile unsigned char *data,volatile unsigned char lenght );
void sendUARTBytes(volatile const char* mystring);
void I2C_INIT();
void I2C_SET_ADDRESS(unsigned char address);
void UART_INIT();
