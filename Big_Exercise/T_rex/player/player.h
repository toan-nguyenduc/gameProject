#ifndef PLAYER_H
#define PLAYER_H
#include "Graphics.h"

#include<cmath>

#define turnRight "image/sprite_r.png"
#define ducking "image/ducking.png"

struct Player {

    SDL_Texture* textureR;
    SDL_Texture* textureDucking;

    int x=100;
    int y=320;
    bool isJumping = false;
    bool isDucking = false;
    const float gravity = 9.8; // Trọng lực
    float jumpVelocity=0;
    float jumpHeight=320;
    const float initialJumpVelocity = 5;

Uint32 lastTime = SDL_GetTicks();

    //Load anh Dino
    void init(Graphics graphics){
        textureR=graphics.loadTexture(turnRight);
        textureDucking=graphics.loadTexture(ducking);
    }

    //Dino di chuyen
    void move(){
        const Uint8* currrentKeyState =SDL_GetKeyboardState(nullptr);
            //Sang phải
        if(currrentKeyState[SDL_SCANCODE_RIGHT]){
            if(x<1490) x+=15;
        }
            //Sang trái
        else if(currrentKeyState[SDL_SCANCODE_LEFT]){
            if(x>0) x-=15;
        }
            //Nhảy lên
        else if(currrentKeyState[SDL_SCANCODE_DOWN]){
            isDucking=true;
        }
        else if(currrentKeyState[SDL_SCANCODE_UP] and !isJumping ){
            isJumping=true;

            jumpHeight-=20;
            jumpVelocity=initialJumpVelocity;
        }
    }

  //  void update(float deltaTime);
    // Hàm để vẽ Dino lên màn hình
    void render( Graphics graphics){
        if(isDucking){
            y+=20;
            graphics.renderTexture(textureDucking,x,y);
            isDucking=false;
            y-=20;
        }
        else{
            graphics.renderTexture(textureR,x,y);
        }
    }

};


#endif // PLAYER_H
