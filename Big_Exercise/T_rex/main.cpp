#include<iostream>

#include "General.h"
#include "LTexture.h"
#include "Background.h"
#include "Sprite.h"

using namespace std;

int main(int argc, char *argv[])
{
    //DO hoa
    Graphics graphics;
    graphics.init();

    SDL_Texture* background=graphics.loadTexture(background_image);

    //Background troi
    ScrollingBackground bgr;
    bgr.setTexture(graphics.loadTexture(ground_image));

    //Nhan vat chuyen dong
    Sprite dino;
    dino.init(graphics,DINO_FRAMES,DINO_CLIPS);

    bool quitGame = false;
    SDL_Event event;
    while(!quitGame){
        while(SDL_PollEvent(&event) != 0){
            if(event.key.keysym.sym == SDLK_TAB) quitGame=true;
        }
        graphics.prepareScene(background);
        dino.tick();
        bgr.scroll(5);
        bgr.render(bgr, graphics);
        dino.renderSprite(graphics);
        graphics.presentScene();
		SDL_Delay(20);
    }

    SDL_DestroyTexture(bgr.texture);

    SDL_Delay(100);
    graphics.quit();

}
