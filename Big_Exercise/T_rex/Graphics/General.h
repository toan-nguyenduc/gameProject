#ifndef GENERAL_H
#define GENERAL_H

//HEADER SDL2
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

//SCREEN INFORMATION
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT =900;
//CONDITION
bool outIntro=false;
bool outPLaying=false;
bool outEnding=false;
bool onMusic=true;
int score=-1;
int vel=10;
#define WINDOW_TITLE "Dino Running"

//IMAGE INTRO
#define intro_image "image/button3.png"
#define menu_image "image/menu.png"
const int INTRO_CLIPS[][4] = {
    {0, 0, 450, 450},
    {450, 0, 450, 450}};
const int INTRO_FRAMES = sizeof(INTRO_CLIPS)/sizeof(int)/4;

//IMAGE OUTRO
#define outro1_image "image/outro1.png"

//IMAGE GROUND AND BACKGROUND
#define background_image "image/background.png"
#define ground_image "image/ground1.png"

//IMAGE DINO RUN
#define dino_image "image/dino.png"

const int DINO_CLIPS[][4] = {
    {  0, 0, 75, 85},
    { 75, 0, 74, 85},
    {150, 0, 75, 85},
    {225, 0, 75, 85},
    {300, 0, 75, 85},
    {375, 0, 75, 85}};
const int DINO_FRAMES = sizeof(DINO_CLIPS)/sizeof(int)/4;

//IMAGE ENEMY
#define enemy_image "image/enemy.png"
const int ENEMY_CLIPS[][4] ={
    {564, 16, 77, 113},
    {438, 37, 107, 85},
    {357, 33, 82, 89},
    {257, 29, 82, 95},
    {178, 15, 73, 111},
    {92, 27,  69, 101},
    {4, 16, 72, 110}};
const int ENEMY_FRAMES = sizeof(ENEMY_CLIPS)/sizeof(int)/4;

//IMAGE TRAP
#define fireball_image "image/lighting.png"

//SOUND AND MUSIC
#define themeSong "sound\\theme.ogg"
#define crash_sound "sound\\introSound.wav"
#define press_sound "sound\\press.wav"
#define laugh_sound "sound\\teemoLaugh.mp3"
#define end_sound "sound\\end.mp3"

//FONT AND TEXT
#define font_file "image\\Pixel.ttf"
#define color_font {100,255,100,150}

#endif // GENERAL_H
