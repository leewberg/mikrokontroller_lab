#include "uart.h"
#include <stdio.h>
#include <sys/types.h>

#define __BUTTON_1_PIN__ 13
#define __BUTTON_2_PIN__ 14
#define __BUTTON_3_PIN__ 15

void button_init(){ 
	GPIO->PIN_CNF[__BUTTON_1_PIN__] = (3 << 2);
	// Fill inn the configuration for the remaining buttons 
	GPIO->PIN_CNF[__BUTTON_2_PIN__] = (3 << 2); //configs the buttons to be pull up on pins, input pins, and connecting them to the input buffer
	GPIO->PIN_CNF[__BUTTON_3_PIN__] = (3 << 2);
}



ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
        }
    return count;
}

int main(){
    // Configure LED Matrix
	for(int i = 17; i <= 20; i++){ //sets the pins as output pins
		GPIO->DIRSET = (1 << i); //sets as output
		GPIO->OUTCLR = (1 << i); //disconnects input buffer
	}
    // Configure buttons -> see button_init()
	button_init();
    uart_init();
    int A = 'A'; //A
    int B = 'B'; //B
	int sleep = 0;
    int LEDon = 1;
	while(1){

		/* Check if button 1 is pressed;
		 * turn on LED matrix if it is. */
		if (!(GPIO->IN & (1 << __BUTTON_1_PIN__))){
			//if button 1 is pressed ... 
			uart_send(A);
            
            LEDon = !(LEDon);
                
    
		}

		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */
		if (!(GPIO->IN & (1 << __BUTTON_2_PIN__))){
			//if button 2 is pressed
			uart_send(B);
		}

        if (!(GPIO->IN & (1 << __BUTTON_3_PIN__))){
            iprintf("The average grade in TTK%d in %d was: %c\n\r",4235,2022,'B');
        }

        if (uart_read() != '\0'){
            if(LEDon){
                for(int i = 17; i <= 20; i++){
                    GPIO -> OUTCLR= (1 << i);
                }
                LEDon = 0;
            }
            else{
                for(int i = 17; i <= 20; i++){
                    GPIO -> OUTSET= (1 << i);
                }
                LEDon = 1;
            }
        }

		sleep = 10000;
		while(--sleep); // Delay
	}

    return 0;
}