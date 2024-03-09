
int row_finder1(void);
int row_finder2(void);
int row_finder3(void);

// Mapping the column and rows with input ports
sbit C3 = P2^5;
sbit C2 = P2^1;
sbit C1 = P2^3;
sbit R4 = P2^4;
sbit R3 = P2^6;
sbit R2 = P2^7;
sbit R1 = P2^2;


int row_finder1() //Function for finding the row for column 1

{

R1=R2=R3=R4=1;

C1=C2=C3=0;

if(R1==0) {
	while(R1==0);
	lcd_write_char('1');
	return 1;
}

else if(R2==0) {
	while(R2==0);
	lcd_write_char('4');
	return 4;
}

else if(R3==0) {
	while(R3==0);
	lcd_write_char('7');
	return 7;
}

else if(R4==0) {
	while(R4==0);
	lcd_write_char('.');
	return 100;
}

}

int row_finder2() //Function for finding the row for column 2

{

R1=R2=R3=R4=1;

C1=C2=C3=0;

if(R1==0) {
	while(R1==0);
	lcd_write_char('2');
	return 2;
}
	

else if(R2==0) {
	while(R2==0);
	lcd_write_char('5');
	return 5;
}

else if(R3==0) {
	while(R3==0);
	lcd_write_char('8');
	return 8;
}
	

else if(R4==0) {
	while(R4==0);
	lcd_write_char('0');
	return 0;
}

}

int row_finder3() //Function for finding the row for column 3

{

R1=R2=R3=R4=1;

C1=C2=C3=0;

if(R1==0) {
	while(R1==0);
	lcd_write_char('3');
	return 3;
}

else if(R2==0) {
	while(R2==0);
	lcd_write_char('6');
	return 6;
}

else if(R3==0) {
	while(R3==0);
	lcd_write_char('9');
	return 9;
}


}
