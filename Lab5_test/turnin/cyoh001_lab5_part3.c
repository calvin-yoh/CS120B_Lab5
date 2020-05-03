/*	Author: cyoh001
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - Secondlude for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <stdlib.h>	
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

enum States { Start, First, Second, Third, Fourth, Fifth }state;
unsigned char tempB = 0x00;
unsigned char tempA = 0x00;

void Tick() {
	tempA = ~PINA;
	switch (state) { //Transitions
	case Start:
		state = First;
		break;
	case First:
		if (tempA == 0x01)
		{
			state = Second;
			break;
		}		
	case Second:
		if (tempA == 0x01)
		{
			state = Third;
			break;
		}
	case Third:
		if (tempA == 0x01)
		{
			state = Fourth;
			break;
		}
	case Fourth:
		if (tempA == 0x01)
		{
			state = Fifth;
			break;
		}
	case Fifth:
		if (tempA == 0x01)
		{
			state = First;
			break;
		}
	default:
		state = Start;
		break;
	}

	switch (state) { //State actions
	case First:
		tempB = 0x05;
		break;
	case Second:
	{
		tempB = 0x0A;
		break;
	}
	case Third:
	{
		tempB = 0x14;
		break;
	}
	case Fourth:
		tempB = 0x28;
		break;
	case Fifth:
	{
		tempB = 0x3F;
		break;
	}
	default:
		tempB = 0x00;
		break;
	}

	PORTB = tempB;
}

int main(void)
{
	state = Start;
	tempC = 0x00;
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	while (1)
	{
		Tick();
	}
	return 0;
}