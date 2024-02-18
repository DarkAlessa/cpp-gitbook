```cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Renderer* windowRenderer = nullptr;
SDL_Texture* texture = nullptr;

int main(int argc, char** argv) {

    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window != nullptr);  // or assert(window);
    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(windowRenderer != nullptr);  // or assert(windowRenderer)
    SDL_Surface* loadedSurface = IMG_Load("../asset/sprite/Sprite-0001.png");
    assert(loadedSurface != nullptr);   // or assert(loadedSurface)
    texture = SDL_CreateTextureFromSurface(windowRenderer, loadedSurface);
    assert(texture != nullptr);     // or assert(texture)
    SDL_FreeSurface(loadedSurface);

    SDL_Rect des;
    des.x = 120;
    des.y = 120;
    des.w = 60;
    des.h = 60;
////////////////////////////////////////////////////////////////////
    bool is_running = true;
    SDL_Event event;
    while (is_running) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_EventType::SDL_is_running:
                    is_running = false;
                    break;
                case SDL_EventType::SDL_MOUSEBUTTONDOWN:
                    des.x = event.button.x;
                    des.y = event.button.y;
                    break;
            }    
        }
        SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(windowRenderer);
        SDL_RenderCopyEx(windowRenderer, texture, NULL, &des, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(windowRenderer);
    }   

////////////////////////////////////////////////////////////////////
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    texture = nullptr;
    windowRenderer = nullptr;
    window = nullptr;
    IMG_is_running();
    SDL_is_running();
    return 0;
}
```
