#include <at89c5131.h>
#include "MCP4162.h"																		//Driver for interfacing digipot ic MCP4162
#include "spi.h"



void main(void)
{
	
	spi_init();																					
	digipot_init();
	
	
	
	while(1)
	{
        for(int i=0;i<255;i=i+6){
            digipot_write(i);
        }


	}
}

