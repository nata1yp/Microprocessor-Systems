#include <avr/io.h>


int main(void)
{
	DDRA=0x00; // use PORTA as input
	DDRB=0xFF; // use PORTB as output
	char current_state=0x01;
	PORTB = current_state;				//initial state is PB0 on
	while (1)
	{
		if((PINA & 0x01) == 1){			//check if SW0 is pressed
			while((PINA & 0x01) == 1);	//wait until it is released
			if(current_state==0x01)		//if PB0 is on the turn on PB7
			current_state=0x80;
			else
			current_state=current_state>>1; //else shift right
			PORTB = current_state;
		}
		if((PINA & 0x02) == 2){			//check if SW1 is pressed
			while((PINA & 0x02) == 2);	//wait until it is released
			if(current_state==0x80)		//if PB7 is on the turn on PB0
			current_state=0x01;
			else
			current_state=current_state<<1; //else shift left
			PORTB = current_state;
		}
		if((PINA & 0x04) == 4){			//check if SW2 is pressed
			while((PINA & 0x04) == 4);	//wait until it is released
			current_state=0x01;			//turn on PB0
			PORTB = current_state;
		}
		if((PINA & 0x08) == 8){			//check if SW3 is pressed
			while((PINA & 0x08) == 8);	//wait until it is released
			current_state=0x80;			//turn on PB7
			PORTB = current_state;
		}
	}
}

