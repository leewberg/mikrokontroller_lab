#ifndef GPIOTE_H
#define GPIOTE_H
#include <stdint.h>

#define GPIOTE ((NRF_GPIOTE_REG*)0x40006000)

typedef struct {
	volatile uint32_t TASKS_OUT[8];//task for writing to pin
	volatile uint32_t RESERVED0[4];
	volatile uint32_t TASKS_SET[8];//action on pin is to set it high
	volatile uint32_t RESERVED1[4];
	volatile uint32_t TASKS_CLR[8];//action on pin is set to low
	volatile uint32_t RESERVED3[32];
	volatile uint32_t EVENTS_IN[8];//event generated from pin
	volatile uint32_t RESERVED4[23];
	volatile uint32_t EVENTS_PORT;//events generated from multiple input GPIO pins w/ SENSE enabled
	volatile uint32_t RESERVED5[97];
	volatile uint32_t INTENSET; //enable interrupt
	volatile uint32_t INTENCLR; //disable interrupt
	volatile uint32_t RESERVED6[129];
	volatile uint32_t CONFIG[8]; //må bruke denne til å konfigurere pins? A: 0:disabled, 1: event mode (input mode), 3: task mode (output mode) B:GPIO pin number C: sets polarity (se datablad) D: sets init output to high or low
} NRF_GPIOTE_REG;


void gpioteInit();

#endif