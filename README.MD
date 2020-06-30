 # nBlocksStudio Generator 
 ## NODE

This node is a 1Hz to 10MHz Frequency Generator

Inputs/Outputs
The 1st input is the DESIRED Frequency value.
The Output is the ACTUAL Frequency value. The difference is due to Integer Divider
The 2nd input Enables the Generator

Parameters
THECLOCK: Is the LPC1768 microcontroller system clock. Usually 96000000(96MHz)
freq: The default desired Frequency, used when all Inputs are not connected

---
The output Port Pin is fixed at P2_5.
This NODE works for LPC1768/69 only.



---
![Generator NODE](generator_server.JPG)


 Author: Nikos Chalikias 


