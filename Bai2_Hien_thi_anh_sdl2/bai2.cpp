#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

using namespace std;

const int WIDTH=1200;
const int HEIGHT=800;
const char * WINDOW_TITLE = "IMAGE";

void logErrorAndExit(const char *msg, const char *error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg,error);
    SDL_Quit();
}

SDL_Window *initSDL(int WIDTH, int HEIGHT,const char* WINDOW_TITLE)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);

    if(window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
        logErrorAndExit("SDL_image error:",IMG_GetError());

    return window;
}

SDL_Renderer *createRenderer(SDL_Window* window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);

    if(renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"linear");
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

    return renderer;
}

void quitSDL(SDL_Window *window, SDL_Renderer *renderer)
{
    IMG_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while(1){
        if ( SDL_PollEvent(&e) != 0 and (e.type == SDL_KEYDOWN or e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer *renderer)
{
    SDL_Rect dest;

    dest.x=x;
    dest.y=y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
}

SDL_Texture *loadTexture(const char *filename, SDL_Renderer *renderer)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(renderer,filename);
    if (texture == NULL)
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

int main(int argc, char* argv[])
{
 SDL_Window *window = initSDL(WIDTH, HEIGHT, WINDOW_TITLE);
 SDL_Renderer *renderer = createRenderer(window);

 SDL_Texture *background = loadTexture("bikiniBottom.jpg", renderer);
 SDL_RenderClear( renderer);

 SDL_RenderPresent(renderer);
 waitUntilKeyPressed();

 SDL_Texture *spongeBob = loadTexture("Spongebob.png", renderer);
 renderTexture(spongeBob, 400, 400, renderer);
 SDL_RenderPresent(renderer);
 waitUntilKeyPressed();

 SDL_DestroyTexture(spongeBob);
 spongeBob = NULL;
 SDL_DestroyTexture(background);
 background = NULL;

 quitSDL(window, renderer);

 return 0;
}
