bool renderWindow();
bool loadMedia();

// Window surface

// Set the window that we will be rendering to
extern SDL_Window* window;

// The surface that is contained by the window
extern SDL_Surface* screenSurface;

// The flawless image that will be rendered
extern SDL_Surface* walter;