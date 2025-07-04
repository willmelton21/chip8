#include "chip8.h"
#include <stdio.h>
#include <string.h>


unsigned  char font[85] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B 0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
   
};




void loadRom(Chip8* c8, char const* filename) {
   const unsigned int memstart = 0x200;
   FILE *fp;
   fp = fopen(filename,"rb");
   if (fp == NULL) {
      perror("error opening file");
   }
   fseek(fp, 0,SEEK_END);
   int size = ftell(fp);
   fseek(fp,0,SEEK_SET);
   fread(c8->memory+memstart,sizeof(int8_t), size,fp);


   fclose(fp);

}

void init(Chip8* c8) {
   printf("c8 pc is %d\n",c8->PC);
   c8->PC = 0x200;
   c8->i = 0;
   c8->delayTimer = 0;
   c8->soundTimer = 0;
   c8->opcode = 0;
   c8->sp = 0;
   memset(c8->memory,0,sizeof(c8->memory));
   memset(c8->display,0,sizeof(c8->display));
   memset(c8->keypad,0,sizeof(c8->keypad));
   memset(c8->varReg,0,sizeof(c8->varReg));

}

char getKey(char key) {

    char ret;
    switch (key) {
    case '1':
        ret = '1';
        break;
    case '2':
        ret = '2';
        break;
    case '3':
        ret = '3';
        break;
    case '4':
        ret = 'c';
        break;
    case 'q':
        ret = '4';
        break;
    case 'w':
        ret = '5';
        break;
    case 'e':
        ret = '6';
        break;
    case 'r':
        ret = 'd';
        break;
    case 'a':
        ret = '7';
        break;
    case 's':
        ret = '8';
        break;
    case 'd':
        ret = '9';
        break;
    case 'f':
        ret = 'e';
        break;
    case 'z':
        ret = 'a';
        break;
    case 'x':
        ret = '0';
        break;
    case 'c':
        ret = 'b';
        break;
    case 'v':
        ret = 'f';
        break;
    default:
        ret = 'z';

    }
    return ret;
}





void popStack(Chip8* c8) {
  
   if (c8->stack[0] < 0) {
        printf("cannot pop on a stack with no val\n");
        return;
   } 
   int i = 0;
    //get to the point where we have no address saved 
    while(c8->stack[i] != 0) {
        i++;
    }
    c8->stack[i-1] = 0; //remove the value behind the first blank val
    //in this case we just set to 0 to represnt blank val
}

void pushStack(Chip8* c8,int16_t addr) {

    int i = 0;
    while(c8->stack[i] != 0) {
        i++;
    }
    c8->stack[i] = addr; //save address at last empty location

}

void updateTimers(Chip8* c8) {

    if(c8->delayTimer > 0) {
        c8->delayTimer--;

    }

    if(c8->soundTimer > 0) {
        c8->soundTimer--;
        //call play sound here
    }

}



