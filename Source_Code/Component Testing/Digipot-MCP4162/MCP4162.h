//include spi.h for using functions from it. Preprocessor directives are used for guarding
//against multiple inclusion of header files, read compiler user guide for more information

#ifndef spi_h                                                                        //if identifier spi_h is not defined then goto next line
    #include "spi.h"                                                            //Include SPI driver file, Driver for uC 8051 SPI module
#endif                                                                                    //end if directive

//Declaration of functions which are contained in this header file

void digipot_init(void);                                             //Initialize slave MCP4162
void digipot_write(unsigned long int);                               // Writes data to data registers of digipot
                                                                                              

unsigned long int command;

sbit cs_digipot = P3^1;                                              //Chip Select for the Digipot

//Function definitions

void digipot_init(void) // Function to intialize digipot
{
    cs_digipot=1;
}


void digipot_write(unsigned long int value) // Function to write resistance value to digipot
{
    
    command = 0x1100;           // Command Byte to set mode and potentiometer
    cs_digipot=0;               // Set CS low to start transmission
    spi_trx(command);           // Send command byte to digipot
    spi_trx(value);             // Send resistance value to digipot
    cs_digipot=1;               // Set CS high to end transmission

    
}


