# MSP430FR2355-temp_monitor
Project created in Code Composer Studio

Hardware: MSP430FR2355,
          ssd1306 128x64 i2c oled display,
          DS18B20 temp sensor

Configuration:
  The MSP430 it’s configured to read one wire DS18B20(P1.5) sensor, send the data to UCA0 UART(P1.6,P1.7) and display the temperature value to oled display(P1.2,P1.3) via i2c.
