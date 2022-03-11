#include <SDL2/SDL.h>
#include <stdio.h>
#include "Window.h"

// Set the window dimensions
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 500;


SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;


void close() {
  // Dealocate the surfaces
  SDL_FreeSurface(walter);
  walter = NULL;

  // Destroy the window
  SDL_DestroyWindow(window);
  window = NULL;

  // Quit the SDL subsystems
  SDL_Quit();
}


bool loadMedia() {
  // Success or yes
  bool success = true;

  // Load walter.
  walter = SDL_LoadBMP("media/walter.bmp");

  if (walter == NULL) {
    printf("An error >:(%s\n", SDL_GetError());

    success = false;
  }

  return success;
}

bool renderWindow() {
  // If there was success or not
  bool success = true;


  // Finally initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL couldn't be initialized :(%s\n", SDL_GetError());

    success = false;

  }

  // If everything goes well, it's go time
  else {
    // Create window and save it as a variable
    window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Arguments that pass through the variable for debug purposes
    if (window == NULL) {
      printf("Shit the window couldn't be initialized %s\n", SDL_GetError());

      success = false;
    }

    // Once everything is fine and dandy, start up the window
    else {
      // Get the surface of the "window" variable
      screenSurface = SDL_GetWindowSurface(window);

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

      // Main game loop
      while (window) {
        
      }
      
    }
  }

  close();

  return success;
}