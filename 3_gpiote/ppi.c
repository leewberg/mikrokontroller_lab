#include "ppi.h"

void ppi_init(){
    //PPI kanal 0 = GPIOTE LED oppg på pin 1
    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]);

    //PPI kanal 1 = GPIOTE LED pin 2
    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]);


    //PPI kanal 2 = GPIOTE LED pin 3
    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]);


    //PPI kanal 3 = GPIOTE LED pin 4
    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]);

    PPI->CHENSET = (1<<0) | (1<<1) | (1<<2) | (1<<3);
}