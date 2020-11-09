/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #7  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	Demo Link: https://youtu.be/OQkp7Hcy3vY
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTB = 0x00;
    
	ADC_init();
	unsigned short x = ADC;
//	unsigned char my_char;
	
     /* Insert your solution below */


    while (1) {
	x = ADC;
	unsigned char tempB = (char)x;
	PORTB = tempB;
	unsigned char tempD = (char)(x >> 8);
	PORTD = tempD;
    }
    return 1;
}
