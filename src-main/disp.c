#include "avr_inc.h"

extern volatile uint8_t vD1_A,vD1_B,vD1_C,vD1_D;
extern volatile uint8_t vD2_A,vD2_B,vD2_C;
extern volatile uint8_t vD3_A,vD3_B,vD3_C;
extern volatile uint8_t vD4_A,vD4_B,vD4_C;
extern volatile uint8_t vD5_A,vD5_B,vD5_C;

volatile uint8_t refresh;

void Disp_Init(void){
    
    //LED
    D_R_LED |= (1<< R_LED);
    P_R_LED |= (1<< R_LED);

    //DATA 7 SEGMENT
    D_ID |= (1<< IA);
    D_ID |= (1<< IB);
    D_ID |= (1<< IC);
    D_ID |= (1<< ID);

    //CONTROL 7 SEGMENT
    D_D1_A |= (1<< D1_A);
    D_D1_B |= (1<< D1_B);
    D_D1_C |= (1<< D1_C);
    D_D1_D |= (1<< D1_D);
    
    D_D2_A |= (1<< D2_A);
    D_D2_B |= (1<< D2_B);
    D_D2_C |= (1<< D2_C);
    
    D_D3_A |= (1<< D3_A);
    D_D3_B |= (1<< D3_B);
    D_D3_C |= (1<< D3_C);
    
    D_D4_A |= (1<< D4_A);
    D_D4_B |= (1<< D4_B);
    D_D4_C |= (1<< D4_C);
    
    D_D5_A |= (1<< D5_A);
    D_D5_B |= (1<< D5_B);
    D_D5_C |= (1<< D5_C);

    Disp_Off();
}

static void PIN_0(uint8_t pin){
    P_ID &= ~(1 << pin);
}

static void PIN_1(uint8_t pin){
    P_ID |= (1 << pin);
}

static void Disp_Set(uint16_t num){

    switch(num){
        case 0: PIN_0(ID);PIN_0(IC);PIN_0(IB);PIN_0(IA);break; //0000
        case 1: PIN_0(ID);PIN_0(IC);PIN_0(IB);PIN_1(IA);break; //0001
        case 2: PIN_0(ID);PIN_0(IC);PIN_1(IB);PIN_0(IA);break; //0010
        case 3: PIN_0(ID);PIN_0(IC);PIN_1(IB);PIN_1(IA);break; //0011
        case 4: PIN_0(ID);PIN_1(IC);PIN_0(IB);PIN_0(IA);break; //0100
        case 5: PIN_0(ID);PIN_1(IC);PIN_0(IB);PIN_1(IA);break; //0101
        case 6: PIN_0(ID);PIN_1(IC);PIN_1(IB);PIN_0(IA);break; //0110
        case 7: PIN_0(ID);PIN_1(IC);PIN_1(IB);PIN_1(IA);break; //0111
        case 8: PIN_1(ID);PIN_0(IC);PIN_0(IB);PIN_0(IA);break; //1000
        case 9: PIN_1(ID);PIN_0(IC);PIN_0(IB);PIN_1(IA);break; //1001
    }

}

static void Disp_View(volatile uint8_t *port, uint8_t pin, uint16_t val){
    Disp_Set(val);
    if(refresh==0){*port &= ~(1 << pin);}
    f_delay(n_delay);
    Disp_Off();
}

void Disp_On(void){
    P_D1_A &= ~(1 << D1_A );
    P_D1_B &= ~(1 << D1_B );
    P_D1_C &= ~(1 << D1_C );
    P_D1_D &= ~(1 << D1_D );
    
    P_D2_A &= ~(1 << D2_A );
    P_D2_B &= ~(1 << D2_B );
    P_D2_C &= ~(1 << D2_C );
    
    P_D3_A &= ~(1 << D3_A );
    P_D3_B &= ~(1 << D3_B );
    P_D3_C &= ~(1 << D3_C );
    
    P_D4_A &= ~(1 << D4_A );
    P_D4_B &= ~(1 << D4_B );
    P_D4_C &= ~(1 << D4_C );
    
    P_D5_A &= ~(1 << D5_A );
    P_D5_B &= ~(1 << D5_B );
    P_D5_C &= ~(1 << D5_C );
}

void Disp_Off(void){
    P_D1_A |= (1 << D1_A );
    P_D1_B |= (1 << D1_B );
    P_D1_C |= (1 << D1_C );
    P_D1_D |= (1 << D1_D );
    
    P_D2_A |= (1 << D2_A );
    P_D2_B |= (1 << D2_B );
    P_D2_C |= (1 << D2_C );
    
    P_D3_A |= (1 << D3_A );
    P_D3_B |= (1 << D3_B );
    P_D3_C |= (1 << D3_C );
    
    P_D4_A |= (1 << D4_A );
    P_D4_B |= (1 << D4_B );
    P_D4_C |= (1 << D4_C );
    
    P_D5_A |= (1 << D5_A );
    P_D5_B |= (1 << D5_B );
    P_D5_C |= (1 << D5_C );
}

void Disp_All(void){
    
    Disp_View(&P_D1_A,D1_A,vD1_A);
    Disp_View(&P_D1_B,D1_B,vD1_B);
    Disp_View(&P_D1_C,D1_C,vD1_C);
    Disp_View(&P_D1_D,D1_D,vD1_D);
    
    Disp_View(&P_D2_A,D2_A,vD2_A);
    Disp_View(&P_D2_B,D2_B,vD2_B);
    Disp_View(&P_D2_C,D2_C,vD2_C);
    
    Disp_View(&P_D3_A,D3_A,vD3_A);
    Disp_View(&P_D3_B,D3_B,vD3_B);
    Disp_View(&P_D3_C,D3_C,vD3_C);
    
    Disp_View(&P_D4_A,D4_A,vD4_A);
    Disp_View(&P_D4_B,D4_B,vD4_B);
    Disp_View(&P_D4_C,D4_C,vD4_C);
    
    Disp_View(&P_D5_A,D5_A,vD5_A);
    Disp_View(&P_D5_B,D5_B,vD5_B);
    Disp_View(&P_D5_C,D5_C,vD5_C);
    
    P_R_LED ^= (1 << R_LED);
    
}