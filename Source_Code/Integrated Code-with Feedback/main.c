#include <at89c5131.h>
#include "lcd.h"
#include "keypad.h"
#include "MCP4162.h"																		
#include "spi.h"
#include "MCP3008.h"

// Initialising the required variables
int i=0;
int digits[4] = {0,0,0,0};
float req_voltage;
int digipot_val=25;
int digipot_val_corrected;
float v_out;
unsigned int adc_out;
float v_err;

void main(void){
        
        // Initialising the peripheral devices
		lcd_init();
		spi_init();
		digipot_init();
        adc_init();
    
		while(1){
			
            // i=5 => all the required digits have been entered by user
            // The required value of resistance is calculated here and sent to the digipot
			if(i==5) {
                
                // Turn off the cursor
				lcd_cmd(0x0C);
                // Calculate the required value of voltage
				req_voltage = digits[0]*10 + digits[1] + digits[3]/10.0;
                // Calculate the value to be sent to digipot
				digipot_val = (int)(280 - (3058/req_voltage));
                
                // Limit the digipot value between 0 and 255
				if(digipot_val<0) digipot_val = 0;
				else if(digipot_val>255) digipot_val = 255;
                
				// Reset the counter for digit number
				i=0;
                
                // Send the required resistance value to digipot
				digipot_write(digipot_val);
                
                msdelay(50);
               
                // Feedback loop to correct the error in voltage
                
                // Reading the supplied voltage using ADC
                adc_out = adc(4);
                // Converting ADC output to voltage in V
                v_out = adc_out*3.2258/1000.0;
                
                // Calculating the error and finding the new digipot value using this error
                v_err = req_voltage - v_out;
                digipot_val_corrected = (int)(280 - (3058/req_voltage+v_err));
                
                // Limiting the digipot value between 0 and 255
                if(digipot_val_corrected<0) digipot_val_corrected = 0;
                else if(digipot_val_corrected>255) digipot_val_corrected = 255;
                
                // Write the corrected value to digipot
                digipot_write(digipot_val_corrected);
                
				msdelay(2000);
				break;

			}
            
            // Reading the digits from keypad
			R1=R2=R3=R4=0;
			C1=C2=C3=1;
	
			if(C1==0){
				int a = row_finder1();
                // Store the entered digit
				digits[i]=a;
                // Increment the counter for digit number
				i=i+1;
				
			}
			else if(C2==0){
				int a = row_finder2();
				digits[i]=a;
				i=i+1;

			}
			else if(C3==0){
				int a = row_finder3();
				digits[i]=a;
				i=i+1;
				
			}
	
		}


}



 
