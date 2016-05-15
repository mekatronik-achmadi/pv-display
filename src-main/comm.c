#include "avr_inc.h"

volatile char data[n_data+1];

volatile uint8_t vD1_A,vD1_B,vD1_C,vD1_D;
volatile uint8_t vD2_A,vD2_B,vD2_C;
volatile uint8_t vD3_A,vD3_B,vD3_C;
volatile uint8_t vD4_A,vD4_B,vD4_C;
volatile uint8_t vD5_A,vD5_B,vD5_C;

extern volatile uint8_t refresh;

static int uart_putchar(char ch,FILE*stream)
{
	if(ch=='\n'){uart_putchar('\r',stream);}
	while ((UCSR1A & (1 << UDRE1)) == 0) {};
	UDR1=ch;
	return 0;
}

static int uart_getchar(FILE*stream)
{
	char temp;
	while ((UCSR1A & (1 << RXC1)) == 0) {};
	temp=UDR1;
//	uart_putchar(temp,stream);
	return(temp);
}

static FILE uart_stdout=FDEV_SETUP_STREAM(uart_putchar,NULL,_FDEV_SETUP_WRITE);
static FILE uart_stdin=FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);

void Comm_Init(void){
    DDRD |= 1<< 2;
    DDRD &= ~(1<< 3);

    PORTD |= 1<< 2;
    PORTD |= 1<< 3;
    
    UCSR1B|=1<<RXEN;
    UCSR1B|=1<<TXEN;
    UCSR1B|=1<<RXCIE;
    
    UBRR1H=(((F_CPU / (BAUD * 16UL))) - 1)>>8;
    UBRR1L=(((F_CPU / (BAUD * 16UL))) - 1);
    
    stdin=&uart_stdin;
    stdout=&uart_stdout;
    
    sei();
}

uint16_t Comm_AtoI(char strdata){
    char convstr[2];
    sprintf(convstr,"%c",strdata);
    return atoi(convstr);
}

//======================================

ISR(USART1_RX_vect){
    Disp_Off();
    refresh=1;
	scanf("%s",data);
    
    if(strlen(data)!=n_data){
        printf("data corrupt\n");
        refresh=0;
    }
    else{
        
        vD1_A=Comm_AtoI(data[0]);
        vD1_B=Comm_AtoI(data[1]);
        vD1_C=Comm_AtoI(data[2]);
        vD1_D=Comm_AtoI(data[3]);
        
        vD2_A=Comm_AtoI(data[4]);
        vD2_B=Comm_AtoI(data[5]);
        vD2_C=Comm_AtoI(data[6]);
        
        vD3_A=Comm_AtoI(data[7]);
        vD3_B=Comm_AtoI(data[8]);
        vD3_C=Comm_AtoI(data[9]);
        
        vD4_A=Comm_AtoI(data[10]);
        vD4_B=Comm_AtoI(data[11]);
        vD4_C=Comm_AtoI(data[12]);
        
        vD5_A=Comm_AtoI(data[13]);
        vD5_B=Comm_AtoI(data[14]);
        vD5_C=Comm_AtoI(data[15]);

    }
    
    refresh=0;
    return;
}