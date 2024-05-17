#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "General.h"
#include "LTexture.h"
#include "Font.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Fireball.h"
#include "Entity.h"
#include "Music.h"
#include "Entity.h"
#include <string>
#include<iostream>

struct Gameplay{
    //Character
    Player dino;
    Enemy teemo;
    Entity collision;
    Fireball ball;
    //MY INFOR
    Font name;
    Font scoreText;
    Font school;
    SDL_Event e;
    //SFX
    Mix_Music* gMusic=Mix_LoadMUS(themeSong);
    Mix_Chunk* crash=Mix_LoadWAV(crash_sound);
    Mix_Chunk* die=Mix_LoadWAV(laugh_sound);
    Mix_Chunk* pressSound=Mix_LoadWAV(press_sound);
    //INTRO
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    void text_init(Graphics graphics){
        name.init("Nguyen Duc Toan - 23021699", graphics,100,50);
        school.init("K68-CA1-UET", graphics,100 ,150);
    }
    void introGame(Graphics graphics, Ground bgr, Intro intro, SDL_Texture* background, Mix_Chunk* gChunk){
        text_init(graphics);
        while(!outIntro){
            while(SDL_PollEvent(&e) != 0){
                if(currentKeyStates[SDL_SCANCODE_UP] or currentKeyStates[SDL_SCANCODE_RIGHT] or currentKeyStates[SDL_SCANCODE_DOWN] or currentKeyStates[SDL_SCANCODE_LEFT]){
                    //outIntro=true;
                    outIntro=true;
                    SDL_FlushEvent(SDL_KEYDOWN);
                }
            }
        graphics.prepareScene(background);
        bgr.scroll(bgr.bgr_speed);
        bgr.render(graphics);
        name.renderText(graphics);
        school.renderText(graphics);
        intro.tick();
        intro.renderIntro(graphics);
        graphics.presentScene();
        SDL_Delay(20);
        }
    }

    //PLAYING GAME
    void playingGame(Graphics graphics, Ground bgr, SDL_Texture* background){
        Mix_PlayChannel( -1, crash, 0 );
        if(score == -1) score=SDL_GetTicks() /1000;
        std::cerr<<SDL_GetTicks()/1000-score<<std::endl;
        if(dino.texture==nullptr){
            dino.init(graphics);
            teemo.init(graphics);
            ball.init(graphics,fireball_image);
        }
        Mix_PlayMusic(gMusic,-1);
        while(!outPLaying){
            scoreText.initS(SDL_GetTicks()/1000-score,graphics,1200,50);
            std::cerr<<SDL_GetTicks()/1000-score<<std::endl;
            graphics.prepareScene(background);
            SDL_PumpEvents();
            bgr.scroll(bgr.bgr_speed);
            bgr.render(graphics);
            scoreText.renderText(graphics);
            dino.tick();
            teemo.tick();
            teemo.spawnEnemies(graphics);
            if(SDL_GetTicks()/1000-score>=10) ball.render(graphics);
            dino.render(graphics);
            if(collision.CheckCollision(dino,teemo) or collision.CheckTrap(dino,ball) )
                outPLaying=true;
            graphics.presentScene();
            scoreText.free();
            SDL_Delay(20);
        }
    }
    //ENDING GAME
    void endGame(bool& quitGame, Graphics graphics, Ground bgr, SDL_Texture* background, SDL_Texture* menu){
        Mix_PlayChannel( -1, die, 0 );
        Mix_PauseMusic();
        graphics.prepareScene(background);
        bgr.render(graphics);
        graphics.renderTexture(menu,350,150);
        scoreText.initS(SDL_GetTicks()/1000-score,graphics,1200,50);
        scoreText.renderText(graphics);
        graphics.presentScene();
        scoreText.free();
        while(!outEnding){
            while(SDL_PollEvent(&e) != 0){
                if(currentKeyStates[SDL_SCANCODE_ESCAPE]){
                    Mix_FreeChunk(pressSound);
                    Mix_FreeMusic(gMusic);
                    Mix_FreeChunk(crash);
                    Mix_FreeChunk(die);
                    quitGame=true;
                    outEnding=true;
                    name.free();
                    school.free();
                    dino.free();
                    teemo.free();
                }
                else if(currentKeyStates[SDL_SCANCODE_R]){
                    Mix_PlayChannel( -1, pressSound, 0 );
                    Mix_RewindMusic();
                    score=-1;
                    outEnding=true;
                    outPLaying=false;
                    bgr.reset();
                    dino.reset();
                    teemo.reset();
                    ball.reset();
                }
            }
        }
    }
};
#endif // GAMEPLAY_H
