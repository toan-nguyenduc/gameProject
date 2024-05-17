#ifndef FIREBALL_H
#define FIREBALL_H

#include "LTexture.h"


struct Fireball{
    SDL_Texture* texture=nullptr;
    int x=1600;
    int y=350;
    int w=200;
    int h=100;
    int high=150;
    bool onScreen=false;
    bool direction;

    void init(Graphics graphics, const char* path){
        texture=graphics.loadTexture(path);
    }

    void render(Graphics graphics) {
        if(!onScreen){
            onScreen=true;
            direction=rand()%2;
            //From right -> left
            if(direction){
                x=1600;
                x-=10;
            }
            //From left->right
            else{
                x=-10;
                x+=10;
            }
        }
        else{
            if(direction){
                if(x>-10){
                    x=x-15;
                }
                else{
                    y=rand()%high+350;
                    onScreen=false;
                }
            }
            else{
                if(x<1600){
                    x=x+15;
                }
                else{
                    y=rand()%high+350;
                    onScreen=false;
                }
            }
        }
        SDL_Rect renderQuad = {x, y, w, h };
        SDL_RenderCopy(graphics.renderer,texture, nullptr, &renderQuad);
    }
    void reset(){
         x=1600;
         y=350;
         onScreen=false;
    }
};

#endif // FIREBALL_H
