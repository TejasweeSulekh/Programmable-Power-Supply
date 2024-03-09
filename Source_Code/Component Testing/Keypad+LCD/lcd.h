/*************************************************
 	lcd.h: Header file for 16x2 LCD interfacing  
**************************************************/

//Functions contained in this header file
void msdelay(unsigned int time);																	//fn takes integer value as an input and generates corresponding delay in milli seconds
void lcd_init(void);																				//Initialize LCD
void lcd_cmd(unsigned char command);																//Sends commands to lcd
void lcd_write_char(unsigned char disp_data);														//display character on a lcd corresponding to input ascii
void int_to_string(unsigned int,unsigned char *temp_string);//convert unsigned int to string of corresponding decimal value 
void lcd_write_string(unsigned char *s);

// Signals to LCD
#define display_port P2      //Data pins connected to port 2 on microcontroller

sbit rs = P0^0;  //RS pin connected to pin 0 of port 0

sbit rw = P0^1;  // RW pin connected to pin 1 of port 0

sbit e =  P0^2;  //E pin connected to pin 2 of port 0

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.

{

    unsigned i,j ;

    for(i=0;i<time;i++)    

    for(j=0;j<1275;j++);

}

void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD

{

    display_port = command;

    rs= 0;

    rw=0;

    e=1;

    msdelay(1);

    e=0;

}

void int_to_string(unsigned int val,unsigned char *temp_str_data) // Function to convert integer data to string
{
      temp_str_data[0]=48+(val/10000);
	  temp_str_data[1]=48+(val%10000/1000);
	  temp_str_data[2]=48+((val%1000)/100);
	  temp_str_data[3]=48+((val%100)/10);
	  temp_str_data[4]=48+(val%10);

}


void lcd_write_char(unsigned char disp_data)  //Function to send display data to LCD

{

    display_port = disp_data;

    rs= 1;

    rw=0;

    e=1;

    msdelay(1);

    e=0;

}

void lcd_write_string(unsigned char *s) // Function to send display string to LCD
{
	while(*s!='\0')
	{
		lcd_write_char(*s++);
	}
}

 void lcd_init()    //Function to prepare the LCD  and get it ready

{

    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD

    msdelay(10);

    lcd_cmd(0x0F);  // turn display ON, cursor blinking

    msdelay(10);

    lcd_cmd(0x01);  //clear screen

    msdelay(10);

    lcd_cmd(0x80);  // bring cursor to position 1 of line 1

    msdelay(10);

}
