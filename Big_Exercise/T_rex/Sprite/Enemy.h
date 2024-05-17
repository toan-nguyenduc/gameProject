#ifndef ENEMY_H
#define ENEMY_H

#include "General.h"
#include "LTexture.h"


struct Enemy {
    SDL_Texture* texture=nullptr;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int animationSpeed=90;
    int enemySpawnTimer=100;
    int teemoSpeed=15;
    int posX=1600;
    int posY=480;
    bool onScreen=false;

    void init(Graphics graphics) {
        texture = graphics.loadTexture(enemy_image);

        SDL_Rect clip;
        for (int i = 0; i < ENEMY_FRAMES; i++) {
            clip.x = ENEMY_CLIPS[i][0];
            clip.y = ENEMY_CLIPS[i][1];
            clip.w = ENEMY_CLIPS[i][2];
            clip.h = ENEMY_CLIPS[i][3];
            clips.push_back(clip);
        }
    }

    void tick() {
        currentFrame = (SDL_GetTicks()/ animationSpeed) % 4;
        //Speed up time
        if(SDL_GetTicks()/1000 - score == vel and teemoSpeed <50){
            teemoSpeed+=3;
            vel+=10;
        }
        //std::cerr<<teemoSpeed<<std::endl;
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }

    void spawnEnemies(Graphics graphics){
        if(!onScreen){
            if(--enemySpawnTimer <=0){
                render(graphics);
                enemySpawnTimer = 20 + (rand() % 90);
            }
        }
        else if(onScreen==true and enemySpawnTimer >0){
            render(graphics);
        }
    }

    void render(Graphics graphics) {
        const SDL_Rect* clip = getCurrentClip();
        if(!onScreen){
            onScreen=true;
            posX-=teemoSpeed;
        }
        else{
            if(posX>0){
                posX-=teemoSpeed;
            }
            else{
                posX=1600;
                onScreen=false;
            }
        }

        SDL_Rect renderQuad = {posX, posY, clip->w, clip->h};
        SDL_RenderCopy(graphics.renderer,texture, clip, &renderQuad);
    }

    void reset(){
        currentFrame = 0;
        animationSpeed=90;
        enemySpawnTimer=100;
        teemoSpeed=15;
        posX=1600;
        posY=480;
        onScreen=false;
    }

    void free(){
        SDL_DestroyTexture(texture);
        texture=nullptr;
    }
};


#endif // ENEMY_H
