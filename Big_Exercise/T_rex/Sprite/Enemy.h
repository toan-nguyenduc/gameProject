#ifndef ENEMY_H
#define ENEMY_H

#include "General.h"
#include "LTexture.h"

struct Enemy {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int animationSpeed=90;
    int enemySpawnTimer;
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
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }

    void spawnEnemies(Graphics graphics){
        std::cerr<<onScreen;
        if(!onScreen){
            std::cerr<<"Check\n";
            if(--enemySpawnTimer <=0){
                render(graphics);
                enemySpawnTimer = 20 + (rand() % 10);
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
            posX-=enemySpeed;
        }
        else{
            if(posX>0) posX-=enemySpeed
                ;
            else{
                posX=1600;
                onScreen=false;
            }
        }

        SDL_Rect renderQuad = {posX, posY, clip->w, clip->h};
        SDL_RenderCopy(graphics.renderer,texture, clip, &renderQuad);
    }

    void free(){
        SDL_DestroyTexture(texture);
    }
};


#endif // ENEMY_H
