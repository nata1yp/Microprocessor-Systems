
#include <avr/io.h>


int main(void)
{
	char x,A,B,C,D,F0,F1;
	DDRA=0xFF; // use PORTA as output
	DDRB=0x00; // use PORTB as input

	/* Replace with your application code */
	while (1)
	{
		x = PINB & 0x0F;	//isolation of the 4 LSBs
		A = x & 0x01;		//A is PB0
		B = x & 0x02;		//B is PB1
		B = B>>1;
		C = x & 0x04;		//C is PB2
		C = C>>2;
		D = x & 0x08;		//D is PB3
		D = D>>3;
		
		F0 = !( (A && !B ) || (B && !C && D));	//calculation of F0
		F1 = ((A || C) && (B || D));			//calculation of F1
		F1 = F1<<1;
		
		PORTA = (F0 | F1);	//output
	}
}