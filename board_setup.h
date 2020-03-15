/*
 * board_setup.h
 *
 * Created: 15/3/2020 1:54:49 μμ
 *  Author: Anestman
 */ 


#ifndef BOARD_SETUP_H_
#define BOARD_SETUP_H_

#include <avr/interrupt.h>

void Clock_external_crystal_16mhz(void); //Use if you have a 16mhz crystal connected

void Clock_internal_rc_32mhz(void); // Use if there is no external crytal connected, 32mhz internal clock


#endif /* BOARD_SETUP_H_ */