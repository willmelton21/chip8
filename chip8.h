#ifndef CHIP8_H
#define CHIP8_H

#include<stdio.h>
#include<stdint.h>


#define MEM_SIZE 4096

typedef struct {
    uint8_t memory[MEM_SIZE];
    int16_t PC;
    int8_t sp; //stack pointer
    int16_t i; //index register
    int16_t stack[1024]; //arbitrary stack size
    int8_t delayTimer; 
    int8_t soundTimer;
    int8_t varReg[16];
    uint8_t keypad[16];
    uint32_t display[64 * 32]; //display bits are 32 for ease with SDL
    uint16_t opcode;

} Chip8;


extern unsigned char font[85];


void loadRom(Chip8* c8, char const* filename);
void init(Chip8* c8); 
char getKey(char key); 
void popStack(Chip8* c8);
void pushStack(Chip8* c8,int16_t addr);
void updateTimers(Chip8* c8);

#endif // CHIP8_H
