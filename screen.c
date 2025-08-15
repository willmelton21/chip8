#include "screen.h"
#include "chip8.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
void initWindow() {

   SDL_Window* window = NULL;

   SDL_Surface* screenSurface = NULL;
   printf("init screen! \n");
   //Initalize SDL
   if ( SDL_Init (SDL_INIT_VIDEO) < 0) {
      printf(" SDL could not initalize! SDL_Error: %s\n", SDL_GetError());
   }
   else {
      //Create Window

      window = SDL_CreateWindow("Chip8",1980,1080,0);
   }

}
