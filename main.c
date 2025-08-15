#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "chip8.h"
#include "screen.h"


int main(int argc, char* argv[]) {

    //initalize everything here

    Chip8 chip8 = {0};
   
    printf("about to init\n"); 
    init(&chip8);

   if (argc != 2) {
      printf("Need to provide file name for arguments\n");
      printf("Usage: %s\n",argv[0]);
      return 1;
   }

    printf("about to enter loop\n");

    initWindow();

    const unsigned int memstart = 0x200;
    
    loadRom(&chip8,argv[1]);
    bool isFirst = true;

    for(;;) { //for fetch, decode, execute loop
       
      //fetch
      uint8_t inst1 = chip8.memory[chip8.PC++];
      uint8_t inst2 = chip8.memory[chip8.PC++];
      uint16_t inst = (inst1 << 8) | inst2; 
      //printf("PC: 0x%03X, inst1: 0x%02X, inst2: 0x%02X, full inst: 0x%04X\n",chip8.PC - 2, inst1, inst2, inst);
      parseInstruction(&chip8, inst);

      //decode
      
        

    }
}
