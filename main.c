
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_LCD_Declarations.h"
#include "AVR_ADC_Declarations.h"

int main(void)
{
	uint16_t x;
	char int_buffer[12]; //string for LCD printing
	
	LCD_Initialize();
	ADC_Initialize();
	
	while(1)
	{
		x = ADC_Read(0); //read ADC value at PA0	
		x = (x * 5) / (1023);
		itoa(x, int_buffer, 10); //for printing Int, 10 for decimal output (as a string)
		LCD_Print(int_buffer);
		_delay_ms(1000);
	}
}
