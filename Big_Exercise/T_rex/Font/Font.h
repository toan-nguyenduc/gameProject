#ifndef FONT_H
#define FONT_H

#include "General.h"
#include "LTexture.h"
#include "string"


struct Font{
    TTF_Font* gFont=nullptr;
    SDL_Texture* texture=nullptr;
    SDL_Color textColor = color_font;
    SDL_Color scoreColor={0, 0, 205, 100};
    int x, y;

    void init(const char* text, Graphics graphics, int _x, int _y){
        x=_x;
        y=_y;
        gFont=TTF_OpenFont(font_file,48);
        SDL_Surface* surface = TTF_RenderText_Solid(gFont, text, textColor);
        if (surface == nullptr) {
            std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
            return;
        }

        texture=SDL_CreateTextureFromSurface(graphics.renderer,surface);
        if (texture == nullptr) {
            std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
            return;
        }

        SDL_FreeSurface(surface);
    }

    void initS(int grade, Graphics graphics, int _x, int _y){
        x=_x;
        y=_y;
        gFont=TTF_OpenFont(font_file,48);
        std::string scoreText="Score: " + std::to_string(grade);
        SDL_Surface* scoreSurface = TTF_RenderText_Solid(gFont, scoreText.c_str(), scoreColor);
        texture=SDL_CreateTextureFromSurface(graphics.renderer, scoreSurface);
        SDL_FreeSurface(scoreSurface);
    }

    void renderText(Graphics graphics){
        graphics.renderTexture(texture,x,y);
    }

    void render(Graphics graphics){
        std::string scoreText="Score: " + std::to_string(SDL_GetTicks()-score);
        SDL_Surface* scoreSurface = TTF_RenderText_Solid(gFont, scoreText.c_str(), scoreColor);
        texture=SDL_CreateTextureFromSurface(graphics.renderer, scoreSurface);
        SDL_FreeSurface(scoreSurface);
        graphics.renderTexture(texture,x,y);
    }


    void free(){
        if (gFont != nullptr) {
            TTF_CloseFont(gFont);
            gFont = nullptr;
        }

        if (texture != nullptr) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }


};

#endif // FONT_H
