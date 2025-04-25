#pragma once
#ifndef PPI_H
#define PPI_H
#include <stdint.h>
#include "gpiote.h"

#define PPI ((NRF_PPI_REG*)0x4001F000)

typedef struct {
	uint32_t EN;
	uint32_t DIS;
} PPI_TASKS_TYPE;

typedef struct {
	uint32_t EEP;
	uint32_t TEP;
} PPI_CHANNEL_TYPE;

typedef struct {
	// Tasks
	volatile PPI_TASKS_TYPE PPI_TASKS[4]; // use [i].EN to aneble channel group i, use [i].DIS to diable channel group i
	// Registers
	volatile uint32_t RESERVED0[312];
	volatile uint32_t CHEN; // channel enable register
	volatile uint32_t CHENSET; //channel enable set register
	volatile uint32_t CHENCLR; //channel enable clear register
	volatile uint32_t RESERVED1;
	volatile PPI_CHANNEL_TYPE PPI_CH[16]; //[i].EEP channel u event end-popint. [i].TEP channel u task end-point
	volatile uint32_t RESERVED2[156];
	volatile uint32_t CHG[4];//channel group i
} NRF_PPI_REG;

#endif
void ppi_init();