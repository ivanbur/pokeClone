//
//  BuildingClass.cpp
//  pokeClone
//
//  Created by MV Admin on 10/10/18.
//  Copyright © 2018 MV Admin. All rights reserved.
//

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "TileClass.cpp"

class Building {
    private:
    Sprite sprite;
    
    public:
    Building(SDL_Texture *image, int startX, int startY, int numberRows, int numberFrames, int sizeOfClipWidth = 64, int sizeOfClipHeight = 64) {
        sprite = Sprite(image, startX, startY, numberRows, numberFrames, sizeOfClipWidth, sizeOfClipHeight);
    }
    
    bool isPlayerEntering(Player player) {
        if ((player.getSprite().getX() > sprite.getX() + sprite.getX() / 2 && player.getSprite().getX() < player.getSprite().getWidth() + sprite.getX() + sprite.getX() / 2) && player.getSprite().getY() == sprite.getY() + sprite.getHeight()) {
            return true;
        } else {
            return false;
        }
    }
    
    Sprite getSprite() {
        return sprite;
    }
};