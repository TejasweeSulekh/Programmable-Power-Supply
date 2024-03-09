#include <at89c5131.h>
#include "keypad.h"


void main(void)
{

    while(0){
        
        // Reading the digits from keypad
        R1=R2=R3=R4=0;
        C1=C2=C3=1;

        if(C1==0){
            row_finder1();
        }
        else if(C2==0){
            row_finder2();
        }
        else if(C3==0){
            row_finder3();
        }

    }
}

