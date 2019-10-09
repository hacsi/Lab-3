/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section: 023
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;

	unsigned short weight = 0x0000;
	unsigned char lastBit = 0x00;

    /* Insert your solution below */
    while (1) {
	weight = PIND << 1;
	lastBit = PINB & 0x01;
	weight = weight | lastBit;

	if (weight >= 70) {
		PORTB = 0x02;
	}
	else if ((weight < 70) && (weight > 5)) {
		PORTB = 0x04;
	}
	else {
		PORTB = 0x00;
	}
	
    }
    return 1;
}

