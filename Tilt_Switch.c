#include <avr/io.h>
#include <util/delay.h>
#include "TM1000Q.h"

short 	check_switchN(int nTilt);		//prototypes
short 	check_switchS(int sTilt);
short 	check_switchE(int eTilt);
short 	check_switchW(int wTilt);

int main() {
	
	DDRD &= ~_BV(DDD3);	//North -Setting switches to input
	DDRD &= ~_BV(DDD2);	//South
	DDRD &= ~_BV(DDD6);	//East
	DDRD &= ~_BV(DDD5);	//West

	DDRB |= _BV(DDB5);	//North -Setting LED's to output
	DDRB |= _BV(DDB4);	//South
	DDRB |= _BV(DDB3);	//East
	DDRB |= _BV(DDB2);	//West
	
	while(1) {

		
		if (check_switchN(north)) {
			PORTB |= _BV(PORTB5);		//Setting North high
			PORTB &= ~_BV(PORTB4);		//Setting South low
		}
		else if (check_switchS(south)) {
			PORTB |= _BV(PORTB4);		//Setting South high
			PORTB &= ~_BV(PORTB5);		//Setting North low
		}
		else {
			PORTB &= ~_BV(PORTB5);		//Setting both low
			PORTB &= ~_BV(PORTB4);
		}
		
		if (check_switchE(east)) {
			PORTB |= _BV(PORTB3);		//Setting East high
			PORTB &= ~_BV(PORTB2);		//Setting West low
		}
		else if (check_switchW(west)) {
			PORTB |= _BV(PORTB2);		//Setting West high
			PORTB &= ~_BV(PORTB3);		//Setting East low
		}
		else {
			PORTB &= ~_BV(PORTB3);		//Setting both low
			PORTB &= ~_BV(PORTB2);
		}
		
		
	}
	return 0;
}


short check_switchN(int nTilt)				//Debounce subroutines
{
	int ret_val = 0;

	if ((PIND & (1 << nTilt)) != 0)
	{
		/* software debounce */
		_delay_ms(50);
		if ((PIND & (1 << nTilt)) != 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}

short check_switchS(int sTilt)
{
	int ret_val = 0;

	if ((PIND & (1 << sTilt)) != 0)
	{
		/* software debounce */
		_delay_ms(50);
		if ((PIND & (1 << sTilt)) != 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}

short check_switchE(int eTilt)
{
	int ret_val = 0;

	if ((PIND & (1 << eTilt)) != 0)
	{
		/* software debounce */
		_delay_ms(50);
		if ((PIND & (1 << eTilt)) != 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}

short check_switchW(int wTilt)
{
	int ret_val = 0;

	if ((PIND & (1 << wTilt)) != 0)
	{
		/* software debounce */
		_delay_ms(50);
		if ((PIND & (1 << wTilt)) != 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}