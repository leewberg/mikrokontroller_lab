#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)__GPIO_BASE_ADDRESS__)
#define __RESERVED1_SIZE__ 118
#define __BUTTON_1_PIN__ 13
#define __BUTTON_2_PIN__ 14
#define __GPIO_BASE_ADDRESS__ 0x50000000
//LED: from P17-P20

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[__RESERVED1_SIZE__];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

void button_init(){ 
	GPIO->PIN_CNF[__BUTTON_1_PIN__] = (3 << 2);
	// Fill inn the configuration for the remaining buttons 
	GPIO->PIN_CNF[__BUTTON_2_PIN__] = (3 << 2); //configs the buttons to be pull up on pins, input pins, and connecting them to the input buffer
}

int main(){
	// Configure LED Matrix
	for(int i = 17; i <= 20; i++){ //sets the pins as output pins
		GPIO->DIRSET = (1 << i); //sets as output
		GPIO->OUTCLR = (1 << i); //disconnects input buffer
	}

	// Configure buttons -> see button_init()
	button_init();

	int sleep = 0;
	while(1){

		/* Check if button 1 is pressed;
		 * turn on LED matrix if it is. */
		if (!(GPIO->IN & (1 << __BUTTON_1_PIN__))){
			//if button 1 is pressed ... 
			for(int i = 17; i <= 20; i++){
				GPIO -> OUTCLR= (1 << i);
			}
		}

		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */
		if (!(GPIO->IN & (1 << __BUTTON_2_PIN__))){
			//if button 2 is pressed
			for(int i = 17; i <= 20; i++){
			 GPIO->OUTSET = (1 << i);
			}
		}

		sleep = 10000;
		while(--sleep); // Delay
	}
	return 0;
}
