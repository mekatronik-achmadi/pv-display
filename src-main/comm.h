#ifndef COMM_H
#define COMM_H

#define BAUD 9600
 
#define n_data 16

void Comm_Init(void);
uint16_t Comm_AtoI(char strdata);

#endif // LED_H