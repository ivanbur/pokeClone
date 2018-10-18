//
//  SpriteClass.cpp
//  pokeClone
//
//  Created by MV Admin on 10/17/18.
//  Copyright © 2018 MV Admin. All rights reserved.
//

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"


class Sprite {
    private:
    int x;
    int y;
    int currentRow;
    int currentFrame;
    int numRows;
    int numFrames;
    int clipSizeWidth;
    int clipSizeHeight;
    SDL_Texture *spriteSheet;
    SDL_Rect *currentSprite;
    
    public:
    Sprite(SDL_Texture *image, int startX, int startY, int numberRows, int numberFrames = 4, int sizeOfClipWidth = 64, int sizeOfClipHeight = 64) {
        spriteSheet = image;
        x = startX;
        y = startY;
        currentRow = 0;
        currentFrame = 0;
        numRows = numberRows;
        numFrames = numberFrames;
        clipSizeWidth = sizeOfClipWidth;
        clipSizeHeight = sizeOfClipHeight;
        currentSprite->x = 0;
        currentSprite->y = 0;
        currentSprite->w = sizeOfClipWidth;
        currentSprite->h = sizeOfClipHeight;
    }
    
    Sprite() {
    }
    
    void setCurrentSprite(int row, int frame) {
        currentSprite->x = frame*clipSizeWidth;
        currentSprite->y = row*clipSizeHeight;
    }
    
    void drawCurrentSprite(SDL_Renderer *renderer, int setX, int setY) {
        x = setX;
        y = setY;
        
        SDL_Rect destination;
        destination.x = x;
        destination.y = y;
        destination.w = clipSizeWidth;
        destination.h = clipSizeHeight;
        
        
        SDL_RenderCopy(renderer, spriteSheet, currentSprite, &destination);
    }
    
    void setX(int setX) {
        x = setX;
    }
    
    void setY(int setY) {
        y = setY;
    }
    
    void setCurrentRow(int setRow) {
        currentRow = setRow;
    }
    
    void setCurrentFrame(int setFrame) {
        currentFrame = setFrame;
    }
    
    int getX() {
        return x;
    }
    
    int getY() {
        return y;
    }
    
    int getCurrentRow() {
        return currentRow;
    }
    
    int getCurrentFrame() {
        return currentFrame;
    }
    
    int getWidth() {
        return clipSizeWidth;
    }
    
    int getHeight() {
        return clipSizeHeight;
    }
};