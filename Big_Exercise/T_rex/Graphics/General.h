#ifndef GENERAL_H
#define GENERAL_H

//Header SDL2
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

//Screen Infor
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT =900;
#define WINDOW_TITLE "Dino Running"

//Image ground and background
#define background_image "image/background.png"
#define ground_image "image/ground1.png"

//Image dino run
#define dino_image "image/dino.png"
const int DINO_CLIPS[][4] = {
    {  0, 0, 75, 85},
    { 75, 0, 74, 85},
    {150, 0, 75, 85},
    {225, 0, 75, 85},
    {300, 0, 75, 85},
    {375, 0, 75, 85}};
const int DINO_FRAMES = sizeof(DINO_CLIPS)/sizeof(int)/4;

#endif // GENERAL_H
