#include<iostream>

#include "General.h"
#include "LTexture.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"

using namespace std;

int main(int argc, char *argv[])
{
    //DO hoa
    Graphics graphics;
    graphics.init();

    Mix_Music *gMusic = graphics.loadMusic(themeSong);
    graphics.play(gMusic);



    SDL_Texture* background=graphics.loadTexture(background_image);

    //Background troi
    ScrollingBackground bgr;
    bgr.setTexture(graphics.loadTexture(ground_image));

    //Nhan vat chuyen dong
    Player dino;
    dino.init(graphics);

    //Enemy
    Enemy teemo;
    teemo.init(graphics);

    //Collision
    Entity collision;

    bool quitGame = false;
    SDL_Event event;
    while(!quitGame){
        while(SDL_PollEvent(&event) != 0){
            if(event.key.keysym.sym == SDLK_TAB) quitGame=true;

            else if(event.key.keysym.sym == SDLK_ESCAPE) system("pause");
        }
        graphics.prepareScene(background);
        dino.tick();
        teemo.tick();
        bgr.scroll(bgrSpeed);
        bgr.render(bgr, graphics);
        teemo.spawnEnemies(graphics);
        dino.render(graphics);
        graphics.presentScene();
        if(collision.CheckCollision(dino,teemo)){
            cerr<<"Ouch"<<endl;
        };
		SDL_Delay(20);
    }

    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    SDL_DestroyTexture(bgr.texture);

    graphics.quit();

}
