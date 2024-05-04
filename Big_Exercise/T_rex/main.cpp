#include "Screen_infor.h"
#include "Graphics.h"
#include "player.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    SDL_Texture* background=graphics.loadTexture("image/background1.jpg");

    Player dino;
    dino.init(graphics);
    Uint32 lastTime = SDL_GetTicks();

    bool quit=true;
    while(quit){
        SDL_Event e;
        while(SDL_PollEvent(&e) != 0){
            if(e.key.keysym.sym == SDLK_TAB) quit=false;
        }
        dino.move();
       // dino.update((SDL_GetTicks()-lastTime)/1000);
        graphics.prepareScene(background);
        dino.render(graphics);
        graphics.presentScene();
    lastTime=SDL_GetTicks();
    }


    graphics.quit();
    return 0;

}
