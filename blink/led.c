#ifndef F_CPU
#define F_CPU 1600000UL // Frequency of controller
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRC = 0xFF; //SEtting DDR of PORT C
	while(1){
		//LED on
		PORTC = 0xFF; //PC0 = High = LED attached on PC0 is ON
		_delay_ms(500);	//Wait 500 milliseconds

		//LED off
		PORTC = 0x00;
		_delay_ms(500);
	}
}
