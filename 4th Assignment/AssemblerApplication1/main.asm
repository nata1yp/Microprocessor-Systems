.include "m16def.inc"

.DEF input=r24
.DEF output=r25
.DEF direction=r22

reset:	ldi r24 , low(RAMEND) ; initialize stack pointer
		out SPL , r24
		ldi r24 , high(RAMEND)
		out SPH , r24
		
		clr input	; initialize PORTC for input
		out DDRC, input
		ser output	; initialize PORTB for output
		out DDRB, output

		ldi output,1
		ldi direction,0		;controls the direction of the led (0->left, 1->right)

main:	in input,PINC
		sbrc input,2		;if input's bit 2 is on then jump to main
		jmp main
		out PORTB,output	;turn on the led
		sbrs direction,0	;if lbs of direction is 0  then call leftshift else call rightshift
		jmp leftshift
		jmp rightshift

leftshift:
		lsl output			;left rotation
		sbrc output,7		;if msb of output is 1 then change direction 
		ldi direction,1
		jmp main

rightshift:
		lsr output			;right rotation
		sbrc output,0		;if lsb of output is 1 then change direction
		ldi direction,0
		jmp main