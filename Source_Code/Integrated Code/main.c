#include <at89c5131.h>
#include "lcd.h"
#include "keypad.h"
#include "MCP4162.h"																		
#include "spi.h"

// Initialising the required variables
int i=0;
int digits[4] = {0,0,0,0};
float req_voltage;
int digipot_val=25;


void main(void){
        
        // Initialising the peripheral devices
		lcd_init();
		spi_init();
		digipot_init();
	
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



 
