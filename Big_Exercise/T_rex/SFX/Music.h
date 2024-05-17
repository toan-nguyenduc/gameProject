#ifndef MUSIC_H
#define MUSIC_H

#include<SDL.h>
#include<SDL_mixer.h>
#include<iostream>
struct Music{
    Mix_Music* gMusic;
    Music() : gMusic(nullptr) {}

    void init(const char* path){
        gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }

    }
    //PlayMusic
    void play(){
        if (gMusic != nullptr) {
            if (Mix_PlayingMusic() == 0) {
                Mix_PlayMusic( gMusic, -1 );
                 std::cerr<<"play music\n";
            }
            else if( Mix_PausedMusic() == 1 ) {
                Mix_ResumeMusic();
            }
        }
    }
    //Pause
    void pause(){
        if (Mix_PlayingMusic() == 1) {
            Mix_PauseMusic();
        }
    }
    //Stop
    void stop(){
        pause();
        Mix_RewindMusic();
    }



    void free(){
        if(gMusic != nullptr){
            Mix_FreeMusic(gMusic);
            gMusic = nullptr;
        }
    }
};
    //Chunk
    Mix_Chunk* loadSound(const char* path){
        Mix_Chunk* gChunk=Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            std::cerr << "Could not load sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
        }
        return gChunk;
    }
    //PlaySound
    void playChunk(Mix_Chunk* gChunk){
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }

    void freeChunk(Mix_Chunk* gChunk){
        if(gChunk != nullptr){
            Mix_FreeChunk(gChunk);
            gChunk = nullptr;
        }
    }

#endif // MUSIC_H
