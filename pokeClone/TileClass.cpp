//
//  TileClass.cpp
//  pokeClone
//
//  Created by MV Admin on 10/10/18.
//  Copyright © 2018 MV Admin. All rights reserved.
//

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "PlayerClass.cpp"

class Tile {
    private:
    Sprite sprite;
    bool traversable;
    
    public:
    Tile(SDL_Texture *image, int startX, int startY, int numberRows, int numberFrames, bool startTraversable = true, int sizeOfClipWidth = 64, int sizeOfClipHeight = 64) {
        sprite = Sprite(image, startX, startY, numberRows, numberFrames, sizeOfClipWidth, sizeOfClipHeight);
        traversable = startTraversable;
    }
    
    bool isPlayerStandingOnTile(Player player) {
        if (player.getSprite().getX() > sprite.getX() && player.getSprite().getX() < sprite.getX() + sprite.getWidth() &&
            player.getSprite().getY() < sprite.getY() && player.getSprite().getY() > sprite.getY() + sprite.getHeight()) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isTraversable() {
        return traversable;
    }
    
    Sprite getSprite() {
        return sprite;
    }
};