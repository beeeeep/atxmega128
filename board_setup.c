/*
 * board_setup.c
 *
 * Created: 15/3/2020 1:55:07 μμ
 *  Author: Anestman
 */ 
#include "board_setup.h"

void Clock_external_crystal_16mhz(void)
{
	#ifndef F_CPU
	#define F_CPU 16000000UL
	#endif
	
	cli();
	OSC.XOSCCTRL=(OSC.XOSCCTRL & ~(OSC_FRQRANGE_gm) & ~(OSC_XOSCSEL_gm))|OSC_FRQRANGE_12TO16_gc|OSC_XOSCSEL_XTAL_1KCLK_gc; //Set 12-16mhz clock 1clk start up time
	OSC.CTRL|=OSC_XOSCEN_bm; //Enable external oscillator
	while(!(OSC.STATUS & OSC_XOSCRDY_bm)); // Wait for the crystal to stabilise
	CPU_CCP=0xD8;  // Disable register protection
	CLK.CTRL=(CLK.CTRL & ~(CLK_SCLKSEL_gm))|CLK_SCLKSEL_XOSC_gc; //Select external oscillator as clock source
	OSC.XOSCFAIL|=OSC_XOSCFDEN_bm; // Activate non-maskable interrupt for external clock failure
	sei();
}

void Clock_internal_rc_32mhz(void)
{	
	OSC.CTRL|=OSC_RC32MEN_bm; // Select 32mhz rc
	CPU_CCP=0xD8; // Disable register protection
	CLK.CTRL=(OSC.CTRL & ~(CLK_SCLKSEL_gm))|CLK_SCLKSEL_RC32M_gc; //Select internal 32mhz oscillator as clock source
}