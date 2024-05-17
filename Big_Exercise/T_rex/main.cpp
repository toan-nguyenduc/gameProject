#include<iostream>
#include<ctime>

#include "General.h"
#include "LTexture.h"
#include "Background.h"
#include "Music.h"
#include "Gameplay.h"


int main(int argc, char *argv[])
{
    srand(time(0));
    //DO hoa
    Graphics graphics;
    graphics.init();

    //Background troi
    SDL_Texture* background=graphics.loadTexture(background_image);
    Ground ground;
    ground.setTexture(graphics.loadTexture(ground_image));

    SDL_Texture* outro1=graphics.loadTexture(outro1_image);

    Intro intro;
    intro.init(graphics);
    Mix_Chunk* gChunk=Mix_LoadWAV("sound\\teemoLaugh");
    SDL_Texture* menu=graphics.loadTexture(menu_image);

    Gameplay game;
    bool quitGame=false;
    while(!quitGame){
        game.introGame(graphics, ground, intro, background, gChunk);
        game.playingGame(graphics, ground,background);
        game.endGame(quitGame, graphics, ground, background, menu);
        outEnding=false;
    }
    graphics.prepareScene(outro1);
    graphics.presentScene();
    Mix_Music* end=Mix_LoadMUS(end_sound);
    Mix_PlayMusic(end,1);
    while(Mix_PlayingMusic()){}
    Mix_FreeMusic(end);

    SDL_DestroyTexture(background);
    SDL_DestroyTexture(outro1);
    ground.free();
    intro.free();
    graphics.quit();
    return 0;
}
