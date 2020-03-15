/*
 * Atxmega128a1u test.c
 *
 * Created: 14/3/2020 6:29:33 μμ
 * Author : Anestman
 */ 

#include <avr/io.h>
#include "board_setup.h"

void Usart_init(USART_t *usart, const usart_rs232_options_t *opt)
{
		bool result;
		sysclk_enable_peripheral_clock(usart);
		usart_set_mode(usart, USART_CMODE_ASYNCHRONOUS_gc);
		
		usart_format_set(usart, opt->charlength, opt->paritytype,
		opt->stopbits);
		result = usart_set_baudrate(usart, opt->baudrate, sysclk_get_per_hz());
		usart_tx_enable(usart);
		usart_rx_enable(usart);
		
		return result;
}

int main(void)
{
	void Clock_external_crystal_16mhz(void);
    /* Replace with your application code */
    while (1) 
    {
	
    }
}

ISR(OSC_OSCF_vect)
{
	
}
