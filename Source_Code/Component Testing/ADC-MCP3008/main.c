#include <at89c5131.h>
#include "lcd.h"																			//Driver for interfacing lcd
#include "mcp3008.h"																		//Driver for interfacing ADC ic MCP3008


char adc_ip_data_ascii[6]={0,0,0,0,0,'\0'};							//string array for saving ascii of input sample

void main(void)
{
	unsigned int adc_data=0;
	
	spi_init();																					
	adc_init();
    lcd_init();
	
	
	while(1)
	{
	 	unsigned int x;
		 
		x = adc(0);														//Read analog voltage value from 0th channel of ADC Ic MCP3008
		adc_data = (unsigned int) (x*3.2258); 							//Converting received 10 bits value to milli volt (3.3*1000*i/p /1023)
		
		lcd_cmd(0x80);													//Move cursor to first line

		int_to_string(adc_data,adc_ip_data_ascii);					    //Converting integer to string of ascii
		
		lcd_write_string(adc_ip_data_ascii);							//Print analog sampled input on lcd
	}
}

