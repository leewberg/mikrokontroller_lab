#include "uart.h"

void uart_init(){
    //init RX as input
    GPIO->PIN_CNF[RXDPIN] = 0;
    //0b0000
    //init TX as output
    GPIO->PIN_CNF[TXDPIN] = 3; //hvorfor trenger vi input buffer også?
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
    UART -> ENABLE = 0x4; //4

    //start recieveing messages. 
    UART -> TASKS_STARTRX = 1;
    
}

void uart_send(char letter){
    //start transmitting messages
    UART -> TASKS_STARTTX = 1; 

    int prevVal = UART -> EVENTS_TXDRDY; //save the previous value, to know if it has been changed

    //we store the ascii value of the character in the TXD register
    UART -> TXD = (int) letter;

    //sjekk om EVENTS_TXDRDY er blitt trigget, for å vite om verdien i TXD har blitt sent

    //stop transmitting messages
    UART -> TASKS_STOPRX = 1; 
    
    //clear the interruption in EVENTS_TXDRDY by setting all bits to 0
    UART -> EVENTS_TXDRDY &= 0;
}

char uart_read(){}