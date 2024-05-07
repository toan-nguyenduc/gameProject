#ifndef SPRITE_H
#define SPRITE_H

#include<vector>
#include "General.h"
#include "LTexture.h"


struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;

    int currentFrame = 0;
    int animationSpeed = 80;
    int x=100;
    int y=500;
    int highJump=200;
    int onGround=500;
    bool isJumping = false;
    bool inAir = false;

    void init(Graphics graphics, int frames, const int _clips [][4]) {
        texture = graphics.loadTexture(dino_image);

        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        //Animation speed
        currentFrame = (SDL_GetTicks()/ animationSpeed) % 4;
        //currentFrame = (currentFrame +1) % clips.size();
        //Move
         const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
         if(currentKeyStates[SDL_SCANCODE_LEFT]){
            if(x>0){
                x-=20;
            }
         }
         else if(currentKeyStates[SDL_SCANCODE_RIGHT]){
            if(x<=1500){
                x+=20;
            }
         }
         else if(currentKeyStates[SDL_SCANCODE_UP] or currentKeyStates[SDL_SCANCODE_SPACE]){
            if(!isJumping){
                isJumping=true;
                inAir=true;
                y-=20;
            }
            else{

            }
         }
         else if(currentKeyStates[SDL_SCANCODE_DOWN]){
            if(inAir){
                inAir=false;
            }
         }
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }

    void renderSprite(Graphics graphics) {
        const SDL_Rect* clip = getCurrentClip();
        if(inAir==true){
            y-=20;
            if(y==highJump) inAir=false;
        }
        else{
            if(y != onGround) y+=20;
            else isJumping=false;
        }
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(graphics.renderer,texture, clip, &renderQuad);
    }
};

#endif // SPRITE_H
