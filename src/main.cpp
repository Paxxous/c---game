#include <SDL2/SDL.h>
#include <stdio.h>
#include "Window.h"

SDL_Surface* walter = NULL;

SDL_Surface* ch = NULL;

int main(int argc, char* args[]) {

  if (!renderWindow()) {
    printf("There was an errror booting up the game\n");
  }

  else {

      // Fill that surface white
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));

      // Update the surface so that it actually shows
      SDL_UpdateWindowSurface(window);

      // load.
      walter = loadMedia("res/game-images/walter.bmp");
      ch = loadMedia("res/game-images/char.bmp");


      // him.
      SDL_BlitSurface(walter, NULL, screenSurface, NULL);

      // you
      SDL_BlitSurface(ch, NULL, screenSurface, NULL);



      // Update the surface so it actually shows
      SDL_UpdateWindowSurface(window);




    // Main game loop

    bool kill = false;

    SDL_Event e;

    while (!kill) {

      // Event handler
      while (SDL_PollEvent(&e) != 0) {

        // On x, close
        if (e.type == SDL_QUIT) {
          kill = true;
        }

        else if (e.type = SDL_KEYDOWN) {
         switch(e.key.keysym.sym) {
           case SDLK_UP:
            printf("up\n");
            break;

           case SDLK_DOWN:
            printf("down\n");
            break;

           case SDLK_RIGHT:
            printf("left\n");
            break;

           case SDLK_LEFT:
            printf("right\n");
            break;
         } 
        }
      }
    }
  }

  close();
  return 0;
}

