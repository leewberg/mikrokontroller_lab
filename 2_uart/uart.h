#include <stdint.h>
#include "gpio.h"

#define RXDPIN 8
#define TXDPIN 6
#define RTSPIN 5
#define CTSPIN 7
#define UART_BASE 0x40002000
#define __BAUDRATE_VAL__ 0x00275000 //have to give BAUDRATE val of 0x00275000 (per page 542 in datablad) to get a baudrate of 9600
/*RX on pin 8, TX on pin 6*/

#define UART ((NRF_UART_REG*)UART_BASE)

typedef struct{
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASTS_STOPTX;
    volatile uint32_t RESERVED0[3]; // 0x01C - 0x010 = 28 - 16 = 12 = 3 ord
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVED1[56]; // enkelt
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVED2[4]; // 0x11C - 0x10C = 284 - 268 = 16 = 4 ord
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVED3[1]; // 0x124 - 0x120 = 292 - 288 = 4 = 1 ord
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVED[7]; // 0x144 - 0x128 = 68 - 40 = 28 = 7 ord
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVED[46]; // 0x200 - 0x148 = 512 - 328 = 184 = 46 ord
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED[63]; // 0x304 - 0x204 = 768 - 516 = 252 = 63 ord
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED[95]; // 0x480 - 0x30C = 1152 - 772 = 380 = 95 ord
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED[31]; // 0x500 - 0x484 = 1280 - 1156 = 124 = 31 ord
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED[1]; // duh
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t REXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED[1]; // 0x524 - 0x520 = 1316 ...
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVED[17]; // 0x56C - 0x528 = 1388 - 1320 = 68 = 17 ord
    volatile uint32_t CONFIG;

}NRF_UART_REG;

void uart_init();
void uart_send(char letter);
char uart_read();