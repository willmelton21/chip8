#include <stdio.h>
#include "chip8.h"


int main(int argc, char* argv[]) {

    //initalize everything here

    Chip8 chip8 = {0};
   
    printf("about to init\n"); 
    init(&chip8);

    printf("about to enter loop\n");

    for(;;) { //for fetch, decode, execute loop
       
       //fetch
       int8_t inst1 = chip8.memory[chip8.PC++];
       int8_t inst2 = chip8.memory[chip8.PC++];
        

    }
}
