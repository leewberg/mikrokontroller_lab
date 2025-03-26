#include "uart.h"

void uart_init(){
    //init RX as input
    GPIO->PIN_CNF[RXDPIN] = 0;
    //0b0000
    //init TX as output
    GPIO->PIN_CNF[TXDPIN] = 3;
    //0b0011
    //hverken av de skal ha pull. se s. 142 i datablad for info om drive config (tviler på at dette er relevant her, da)

    //config pin number for UART (PSELRXD)
    UART -> PSELRXD = RXDPIN;
    UART -> PSELTXD = TXDPIN;

    UART -> BAUDRATE = __BAUDRATE_VAL__; //change the baudrate so we get one of 9600

    //have to tell the UART that we have no CTS or RTS connections
    UART -> PSELCTS = 0xFFFFFFFF;
    UART -> PSELRTS = 0xFFFFFFFF;

    //turn on UART module
    UART -> ENABLE = 4;

    //start recieveing messages. 
    UART -> TASKS_STARTRX = 1;
    
}

void uart_send(char letter){
    
}

char uart_read(){}