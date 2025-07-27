#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "chip8.h"



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

    const unsigned int memstart = 0x200;

    loadRom(&chip8,argv[1]);
    bool isFirst = true;

    for(;;) { //for fetch, decode, execute loop
       
      //fetch
      int8_t inst1 = chip8.memory[memstart + chip8.PC++];
      printf("inst 1 location is %d\n",memstart + chip8.PC);
      int8_t inst2 = chip8.memory[memstart + chip8.PC++];
      printf("inst 1 is %" PRIi8"\n",inst1);
      printf("inst 2 is %" PRIi8"\n",inst2);
      printf("inst 2 location is %d\n",memstart + chip8.PC);
      int16_t inst = (inst2 << 8) | inst1;
      printf("full inst is %hhX\n",inst);

      //decode
      
        

    }
}
