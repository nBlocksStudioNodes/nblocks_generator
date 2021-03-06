#ifndef __NB_Generator
#define __NB_Generator

#include "nworkbench.h"

class nBlock_Generator: public nBlockNode {
public:
    nBlock_Generator(uint32_t THECLOCK, uint32_t freq);
    uint32_t outputAvailable(uint32_t outputNumber);
    uint32_t readOutput(uint32_t outputNumber);
    void triggerInput(nBlocks_Message message);
    void step(void);
private:
    fifo internal_fifo;
    uint32_t input_0;
    uint32_t system_clock;
};

#endif
