/*
 * DS18B20.h
 *
 *  Created on: May 27, 2020
 *      Author: kyme32
 */

#define WIRE_PIN BIT5
#define WIRE_IN P1IN
#define WIRE_OUT P1OUT
#define WIRE_DIR P1DIR


void reset_DS18B20(void);
void send_DS18B20(char data);
float read_DS18B20();
float get_data_DS18B20();
