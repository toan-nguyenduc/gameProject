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
#define bgrSpeed 5

//Image dino run
#define dino_image "image/dino.png"
#define dinoSpeed 80
const int DINO_CLIPS[][4] = {
    {  0, 0, 75, 85},
    { 75, 0, 74, 85},
    {150, 0, 75, 85},
    {225, 0, 75, 85},
    {300, 0, 75, 85},
    {375, 0, 75, 85}};
const int DINO_FRAMES = sizeof(DINO_CLIPS)/sizeof(int)/4;

//Image enemy
#define enemy_image "image/enemy.png"
#define enemySpeed 16
const int ENEMY_CLIPS[][4] ={
    {564, 16, 77, 113},
    {438, 37, 107, 85},
    {357, 33, 82, 89},
    {257, 29, 82, 95},
    {178, 15, 73, 111},
    {92, 27,  69, 101},
    {4, 16, 72, 110}};
const int ENEMY_FRAMES = sizeof(ENEMY_CLIPS)/sizeof(int)/4;

//Sound and Music
#define themeSong "sound\\theme.ogg"

#endif // GENERAL_H
