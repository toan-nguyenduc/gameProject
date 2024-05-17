#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include "General.h"
#include "LTexture.h"

struct Player {
    SDL_Texture* texture=nullptr;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int dinoSpeed = 80;
    int x=100;
    int y=500;
    int highJump=200;
    int onGround=500;
    bool isJumping = false;
    bool inAir = false;

    void init(Graphics graphics) {
        texture = graphics.loadTexture(dino_image);

        SDL_Rect clip;
        for (int i = 0; i < DINO_FRAMES; i++) {
            clip.x = DINO_CLIPS[i][0];
            clip.y = DINO_CLIPS[i][1];
            clip.w = DINO_CLIPS[i][2];
            clip.h = DINO_CLIPS[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        //Animation speed
        currentFrame = (SDL_GetTicks()/ dinoSpeed) % 4;
        if(SDL_GetTicks()/1000 - score == vel and dinoSpeed > 60){
            dinoSpeed-=5;
        }
        //Move
         const Uint8* currentKeyStates=SDL_GetKeyboardState(NULL);
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
         else if(currentKeyStates[SDL_SCANCODE_UP]){
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
    //Ham ve dino
    void render(Graphics graphics) {
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
    //Ham reset
    void reset(){
        currentFrame = 0;
        dinoSpeed = 80;
        x=100;
        y=500;
        highJump=200;
        onGround=500;
        isJumping = false;
        inAir = false;
    }
    //Ham huy
    void free(){
        SDL_DestroyTexture(texture);
        texture=nullptr;
    }
};

#endif // PLAYER_H
