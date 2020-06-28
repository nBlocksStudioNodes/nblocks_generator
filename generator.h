#ifndef __NB_Generator
#define __NB_Generator

#include "nworkbench.h"

class nBlock_Generator: public nBlockNode {
public:
    nBlock_Generator(uint32_t CLOCK);
    uint32_t outputAvailable(uint32_t outputfrequency);
    uint32_t readOutput(uint32_t outputFrequency);
    void triggerInput(uint32_t inputFrequency);
    void step(void);
private:
    fifo internal_fifo;
    uint32_t input_0;
    PwmOut _pwmo;
};

#endif
