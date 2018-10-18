//
//  main.cpp
//  pokeClone
//
//  Created by MV Admin on 10/3/18.
//  Copyright © 2018 MV Admin. All rights reserved.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "string"

void logSDLError(const std::string &msg);

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;
const int TILE_SIZE = 64;
const int CHARACTER_W = 64;
const int CHARACTER_H = 64;
const int GAME_SPEED = 1;

bool pressedLeft;
bool pressedRight;
bool pressedUp;
bool pressedDown;

int main(int argc, const char * argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "sdl_init error\n";
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("PokeClone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == nullptr) {
        logSDLError("SDL_Window");
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == nullptr) {
        logSDLError("SDL_Renderer");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    if (IMG_Init(IMG_INIT_PNG) & (IMG_INIT_PNG != IMG_INIT_PNG)) {
        logSDLError("IMG_INIT_PNG");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    SDL_Event e;
    bool pressedQuit = false;
    
    
    
    return 0;
}

void logSDLError(const std::string &msg) {
    std::cout << msg << " error: " << SDL_GetError() << std::endl;
}