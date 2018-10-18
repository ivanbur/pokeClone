//
//  PlayerClass.cpp
//  pokeClone
//
//  Created by MV Admin on 10/3/18.
//  Copyright © 2018 MV Admin. All rights reserved.
//

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SpriteClass.cpp"

class Player {
    private:
    Sprite sprite;
    
    public:
    Player(SDL_Texture *image, int startX, int startY, int numberRows, int numberFrames = 4, int sizeOfClipWidth = 64, int sizeOfClipHeight = 64) {
        sprite = Sprite(image, startX, startY, numberRows, numberFrames, sizeOfClipWidth, sizeOfClipHeight);
    }
    
    Player() {
        
    }
    
    Sprite getSprite() {
        return sprite;
    }
};