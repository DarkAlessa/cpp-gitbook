### main.cpp
```cpp
#include "app.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {

    init("Dark Alessa", 640, 480);
    loadTexture("../asset/sprite/Sprite-0001.png");

    SDL_Event event;
    while (loop(&event)) {
        present();
    }

    kill();
    return 0;
}
```

### app.h
```cpp
#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#define NDEBUG
#include <cassert>

void init(const char*, int, int);

void loadTexture(const char*);

bool loop(SDL_Event*);

void present();

void kill();

#endif // APP_H
```

### app.cpp
```cpp
#include "app.h"

SDL_Window* window = nullptr;
SDL_Renderer* windowRenderer = nullptr;
SDL_Texture* texture = nullptr;

SDL_Rect des = {.x = 120, .y = 120, .w = 60, .h = 60};

void init(const char* win_name, int x, int y) {
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
    window = SDL_CreateWindow(win_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN);
    assert(window);
    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(windowRenderer);
}

//////////////////////////////////////////////
void loadTexture(const char* path) {
	SDL_Surface* loadedSurface = IMG_Load(path);
    assert(loadedSurface);
    texture = SDL_CreateTextureFromSurface(windowRenderer, loadedSurface);
    assert(texture);
    SDL_FreeSurface(loadedSurface);
}

//////////////////////////////////////////////
bool loop(SDL_Event* e) {
    while (SDL_PollEvent(e) != 0) {
        switch (e->type) {
            case SDL_EventType::SDL_QUIT:
                return false;
                break;
            case SDL_EventType::SDL_MOUSEBUTTONDOWN:
                des.x = e->button.x;
                des.y = e->button.y;
                break;
        }    
    }
    return true;
}

//////////////////////////////////////////////
void present() {
	SDL_SetRenderDrawColor(windowRenderer, 60, 62, 62, 255);
    SDL_RenderClear(windowRenderer);
    SDL_RenderCopyEx(windowRenderer, texture, NULL, &des, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(windowRenderer);
}

//////////////////////////////////////////////
void kill() {
	SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    texture = nullptr;
    windowRenderer = nullptr;
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
```