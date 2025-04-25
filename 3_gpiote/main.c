#include "gpiote.h"
#include "ppi.h"
#include "gpio.h"


#define __BUTTON_1_PIN__ 13


#define DELAY_LOOP_CONSTANT_1MS 16000

void init_LED(){
    for(int i = 17; i <= 20; i++){ //sets the pins as output pins
		GPIO->DIRSET = (1 << i); //sets as output
		GPIO->OUTCLR = (1 << i); //disconnects input buffer
	}
}

void button_init(){
    GPIO->PIN_CNF[__BUTTON_1_PIN__] = (3 << 2);
}


int main(){
    button_init();
    init_LED();
    gpioteInit();
    ppi_init();
    while(1){
        __asm__("nop");
    }

    return 0;
}