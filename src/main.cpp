#include <SDL2/SDL.h>
#include <stdio.h>
#include "Window.h"

SDL_Surface* walter = NULL;

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
      loadMedia();

      // Apply the image
      SDL_BlitSurface(walter, NULL, screenSurface, NULL);

      // Update the surface so it actually shows
      SDL_UpdateWindowSurface(window);



    // do something or something
    bool kill = false;

    SDL_Event e;

    //while program is running
    while (!kill) {

      // Event handler
      while (SDL_PollEvent(&e) != 0) {

        // On x, close
        if (e.type == SDL_QUIT) {
          kill = true;
        }

      }
    }
  }

  close();
  return 0;
}

