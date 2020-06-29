#include "generator.h"

// Generator
nBlock_Generator::nBlock_Generator(int32_t THECLOCK):{             // One Parameter: THECLOCK of the LPC1768
    return;
}
uint32_t nBlock_Generator::outputAvailable(uint32_t outputNumber) { //Check for available Carrots
    return internal_fifo.available();
}
uint32_t nBlock_Generator::readOutput(uint32_t outputNumber) {  // Pass the Carrot to the Next
    uint32_t tmp;
    internal_fifo.read(&tmp);
    return tmp;
}

void nBlock_Generator::triggerInput(uint32_t inputNumber, uint32_t value) // Scan the inputs and prepare Carrot
    { 
    	PwmOut fmclck(P2_5);                    					// for RESERVE pin21(P2_5) as PWM1[6]
	    int32_t divider;
	    uint32_t outFrequency;
    if (inputNumber == 0){                                       // "value" contains the Frequency
	    divider = THECLOCK/value;
	    outFrequency = THECLOCK/divider;
	    LPC_PWM1->TCR = (1 << 1);               				// 1)Reset counter, disable PWM
        LPC_SC->PCLKSEL0 &= ~(0x3 << 12);  
        LPC_SC->PCLKSEL0 |= (1 << 12);          				// 2)Set peripheral clock divider to /1, i.e. system clock
        LPC_PWM1->MR0 = divider - 1;            				// 3)Match Register 0 is shared period counter for all PWM1
        LPC_PWM1->MR6 = (divider + 1)>> 1;      				// 
        LPC_PWM1->LER |= 1;                     			    // 4)Start updating at next period start                       
    }
    if(inputNumber ==1){                                        // "value" contains the ENABLE
        if(value > 0 ) {LPC_PWM1->TCR = (1 << 0) || (1 << 3); } // 5)Enable counter and PWM 
	    if(value == 0) {LPC_PWM1->TCR = (1 << 1);             } // 1)Reset counter, disable PWM 
    } 
    internal_fifo.put(outFrequency);                            // pass calculated outFrequency to fifo	              									 
}
void nBlock_Generator::step(void) {
    uint32_t tmp;
    internal_fifo.get(&tmp);
    return;
}
