#ifndef DISP_H
#define DISP_H

#include <inttypes.h>

/*
 * LED
 */
#define R_LED 0
#define D_R_LED DDRB
#define P_R_LED PORTB

/*
 * Data to 4511
 */

#define IA 0
#define IB 1
#define IC 2
#define ID 3
#define D_ID DDRA
#define P_ID PORTA

/*
 * Control to 7-Segment
 */

#define f_delay _delay_ms
#define n_delay 1

// remap from socket 6
#define D1_D 3
#define D1_C 6
#define D1_B 5
#define D1_A 4
#define D_D1_D DDRC
#define D_D1_C DDRC
#define D_D1_B DDRC
#define D_D1_A DDRC
#define P_D1_D PORTC
#define P_D1_C PORTC
#define P_D1_B PORTC
#define P_D1_A PORTC

// remap from socket 5
#define D2_C 7
#define D2_B 2
#define D2_A 7
#define D_D2_C DDRA
#define D_D2_B DDRG
#define D_D2_A DDRC
#define P_D2_C PORTA
#define P_D2_B PORTG
#define P_D2_A PORTC 

// remap from socket 4
#define D3_C 4
#define D3_B 5
#define D3_A 6
#define D_D3_C DDRA
#define D_D3_B DDRA
#define D_D3_A DDRA
#define P_D3_C PORTA
#define P_D3_B PORTA
#define P_D3_A PORTA

// remap from socket 2
#define D4_C 3
#define D4_B 4
#define D4_A 5
#define D_D4_C DDRF
#define D_D4_B DDRF
#define D_D4_A DDRF
#define P_D4_C PORTF
#define P_D4_B PORTF
#define P_D4_A PORTF

// remap from socket 1
#define D5_C 0
#define D5_B 1
#define D5_A 2
#define D_D5_C DDRF
#define D_D5_B DDRF
#define D_D5_A DDRF
#define P_D5_C PORTF
#define P_D5_B PORTF
#define P_D5_A PORTF// remap from socket 2
#define D4_C 3
#define D4_B 4
#define D4_A 5
#define D_D4_C DDRF
#define D_D4_B DDRF
#define D_D4_A DDRF
#define P_D4_C PORTF
#define P_D4_B PORTF
#define P_D4_A PORTF

void Disp_On(void);
void Disp_Off(void);
void Disp_Init(void);
void Disp_All(void);

#endif // DISP_H
