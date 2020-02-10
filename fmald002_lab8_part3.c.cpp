/*	Author: fmald002
 *  Partner(s) Name: Robert Rivera
 *	Lab Section: 22
 *	Assignment: Lab # 8 Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//  in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	ADC_init();
	unsigned short x = 0x00;
	unsigned short tmpB = 0x00;
	unsigned short tmpC = 0x00;
	while (1) {
		x = ADC;
		if (x >= (856/2)) {
			tmpB = 1;
			} else {
			tmpB = 0;
		}
		PORTB = tmpB;
	}
}


