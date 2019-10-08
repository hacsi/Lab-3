/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #3
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char fuelLevel = 0x00;
	unsigned char seatbelt = 0x00;
	unsigned char fastenIcon = 0x00;

    /* Insert your solution below */
    while (1) {
	seatbelt = PINA & 0x30;
	fuelLevel = PINA & 0x0F;
	if (seatbelt == 0x30) {
		fastenIcon = 0x80;
	}


	switch (fuelLevel) {
		case 1:
		case 2:
			PORTC = 0x60 | fastenIcon;
			break;
		case 3:
		case 4:
			PORTC = 0x70 | fastenIcon;
			break;
		case 5:
		case 6:
			PORTC = 0x38 | fastenIcon;
			break;
		case 7:
		case 8:
		case 9:
			PORTC = 0x3C | fastenIcon;
			break;
		case 10:
		case 11:
		case 12:
			PORTC = 0x3E | fastenIcon;
			break;
		case 13:
		case 14:
		case 15:
			PORTC = 0x3F | fastenIcon;
			break;
		default:
			PORTC = 0x40 | fastenIcon;
			break;
	}
    }
    return 1;
}

