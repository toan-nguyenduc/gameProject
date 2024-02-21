#include<stdio.h>
#include<SDL.h>
#include<iostream>
using namespace std;
//Screen dimension(kich thuoc) constants
const int SCREEN_WIDTH=1400;
const int SCREEN_HEIGHT = 900;
const char* WINDOW_TITLE="Chào mít ngu !!!";
//Ham bao loi SDL
void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"%s: %s", msg, error);
    SDL_Quit();
}

//Mo cua so ve
SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!= 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window*window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(window==nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    return window;
}

//Khoi tao but ve
SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //khi chay trong moi truong binh thuong
    //khi chay o may ao
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if(renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer,SCREEN_HEIGHT,SCREEN_WIDTH);

    return renderer;
}



//Giai phong SDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Extension: doi nhan phim
void waitUntilKeyPressed()
{
    SDL_Event e;
    while(true){
        if ( SDL_PollEvent(&e) != 0 and (e.type == SDL_KEYDOWN or e.type == SDL_QUIT)) return;
        SDL_Delay(100);
    }
}
int main(int argc, char* argv[]){
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    //drwing code here
    //use SDL_RenderPresent(renderer) to show it

    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
