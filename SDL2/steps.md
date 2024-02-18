1 Include the SDL2 headers in your project
2 Initialize SDL2
3 Create a window
4 Create a renderer (optional, for graphics)
5 Main loop
  - Event handler
6 Clean up
7 Compile and run


Example
```cpp
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL2 initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool isRunning = true;

    // Event handler
    SDL_Event event;

    // Main loop
    while (isRunning) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // Application logic and drawing code go here
        // For this example, we're just keeping the window open without any graphics

        // Delay to control frame rate (approx. 60 FPS in this case)
        SDL_Delay(16);
    }

    // Clean up and exit
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
```
