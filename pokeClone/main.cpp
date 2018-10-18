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
#include "BuildingClass.cpp"

void logSDLError(const std::string &msg);
SDL_Texture* loadIMGTexture(const std::string &file, SDL_Renderer *renderer);

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;
const int TILE_SIZE = 64;
const int CHARACTER_W = 64;
const int CHARACTER_H = 64;
const int GAME_SPEED = 1;
const int MOVEMENT_DISTANCE = 32;

bool pressedLeft;
bool pressedRight;
bool pressedUp;
bool pressedDown;

Player player;

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
    
    player = Player(loadIMGTexture("test.png", renderer), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 4);
    Sprite playerSprite = player.getSprite();
    
    SDL_Event e;
    bool pressedQuit = false;
    
    while (!pressedQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                pressedQuit = true;
            }
            
            if (e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        pressedUp = true;
                        break;
                    case SDLK_DOWN:
                        pressedDown = true;
                        break;
                    case SDLK_RIGHT:
                        pressedRight = true;
                        break;
                    case SDLK_LEFT:
                        pressedLeft = true;
                        break;
                    case SDLK_ESCAPE:
                        pressedQuit = true;
                        break;
                    default:
                        break;
                }
            }
            
            if (e.type == SDL_KEYUP) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        pressedUp = false;
                        break;
                    case SDLK_DOWN:
                        pressedDown = false;
                        break;
                    case SDLK_RIGHT:
                        pressedRight = false;
                        break;
                    case SDLK_LEFT:
                        pressedLeft = false;
                        break;
                    default:
                        break;
                }
            }
        }
        
        if (pressedUp) {
            playerSprite.setY(playerSprite.getY() - MOVEMENT_DISTANCE);
        }
        
        if (pressedDown) {
            playerSprite.setY(playerSprite.getY() + MOVEMENT_DISTANCE);
        }
        
        if (pressedRight) {
            playerSprite.setX(playerSprite.getX() + MOVEMENT_DISTANCE);
        }
        
        if (pressedLeft) {
            playerSprite.setX(playerSprite.getX() - MOVEMENT_DISTANCE);
        }
        
        SDL_RenderClear(renderer);
        playerSprite.drawCurrentSprite(renderer, playerSprite.getX(), playerSprite.getY());
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}

void logSDLError(const std::string &msg) {
    std::cout << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture* loadIMGTexture(const std::string &file, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture == nullptr) {
        logSDLError("IMG_LoadTexture");
    }
    
    return texture;
}