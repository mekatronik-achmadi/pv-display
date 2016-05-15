#include "avr_inc.h"

int main(void) {
    Comm_Init();
    Disp_Init();
    
    while(1){
        Disp_All();
        //Disp_On();
    }
}
