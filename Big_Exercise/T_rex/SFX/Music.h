#ifndef MUSIC_H
#define MUSIC_H

//Initialize SDL_mixer
struct Music{
    Mix_Music *gMusic;
    //Tao nhac
    void init(){
        gMusic=Mix_LoadMUS(themeSong);
        if(gMusic == nullptr){
            logErrorAndExit("Could not load music! SDL_mixer Error: ", Mix_GetError());
        }
    }

    void play(){
        if(gMusic != nullptr){
            if(Mix_PlayingMusic()==0){
                Mix_PlayMusic(gMusic,-1);
            }
        }
        else if(Mix_PausedMusic()==1{
            Mix_ResumeMusic();
        }
    }

    void pause(){
        if(Mix_PlayingMusic()==1){
            Mix_PauseMusic();
        }
    }

    void stop(){
        pause();
        Mix_RewindMusic();
    }

    void free(){
        Mix_FreeMusic(gMusic);
        Mix_Quit();
    }

};

#endif // MUSIC_H
