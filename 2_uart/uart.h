#include <stdint.h>
#include <gpio.h>

#define UART ((NRF_UART_REG*)0x40002000)

typedef struct {

} NRF_UART_REG;


void uart_init();
void uart_send(char letter);
char uart_read();

