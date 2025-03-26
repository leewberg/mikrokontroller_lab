#include <stdint.h>
#include "gpio.h"

#define RXDPIN 8
#define TXDPIN 6
#define RTSPIN 5
#define CTSPIN 7
#define UART_BASE 0x40002000
#define RESERVED0_SIZE 0
#define __BAUDRATE_VAL__ 0x00275000 //have to give BAUDRATE val of 0x00275000 (per page 542 in datablad) to get a baudrate of 9600
/*RX on pin 8, TX on pin 6*/

#define UART ((NRF_UART_REG*)UART_BASE)

typedef struct{
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASTS_STOPTX;

    volatile uint32_t RESERVED0[RESERVED0_SIZE];

    volatile uint32_t TASKS_SUSPEND;

    //RESERVED1

    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t EVENTS_TXDRDY;

    //RESERVED2

    volatile uint32_t EVENTS_ERROR;

    //RESERVED3
    volatile uint32_t EVENTS_RXTO;

    //RESERVED4
    volatile uint32_t SHORTS;
    //RESERVED5
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    //RESERVED6
    volatile uint32_t ERRORSRC;
    //RESERVED7
    volatile uint32_t ENABLE;
    //RESERVED8
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t REXD;
    volatile uint32_t TXD;
    //RESERVED
    volatile uint32_t BAUDRATE;
    //RESERVED
    volatile uint32_t CONFIG;

}NRF_UART_REG;

void uart_init();
void uart_send(char letter);
char uart_read();