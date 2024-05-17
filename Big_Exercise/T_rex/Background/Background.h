#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "LTexture.h"
#include <vector>

struct Ground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;
    int bgr_speed = 5;
    int vel_bgr=10;

    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(int distance) {
        if(SDL_GetTicks()/1000 - score == vel and vel % vel_bgr ==0 and bgr_speed<30){
            bgr_speed+=2;
        }
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }

    void render(Graphics graphics){
        graphics.renderTexture(texture, scrollingOffset, 0);
        graphics.renderTexture(texture, scrollingOffset -width, 0);
    }

    void reset(){
        scrollingOffset = 0;
        width, height;
        bgr_speed = 5;
        vel_bgr=10;
    }

    void free(){
        SDL_DestroyTexture(texture);
    }

};

struct Intro {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int x=550;
    int y=250;

    void init(Graphics graphics) {
        texture = graphics.loadTexture(intro_image);
        SDL_Rect clip;
        for (int i = 0; i < INTRO_FRAMES; i++) {
            clip.x = INTRO_CLIPS[i][0];
            clip.y = INTRO_CLIPS[i][1];
            clip.w = INTRO_CLIPS[i][2];
            clip.h = INTRO_CLIPS[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        currentFrame = (SDL_GetTicks()/ 300) % 4;
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }

    void renderIntro(Graphics graphics) {
        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(graphics.renderer,texture, clip, &renderQuad);
    }


    void free(){
        SDL_DestroyTexture(texture);
        texture=nullptr;
    }

};

#endif // BACKGROUND_H
