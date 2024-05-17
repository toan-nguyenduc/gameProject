#ifndef ENTITY_H
#define ENTITY_H

#include "Player.h"
#include "Enemy.h"
#include "Fireball.h"
#include "SDL.h"

struct Entity {
	bool CheckCollision(Player dino, Enemy teemo){
        bool check = false ;
        SDL_Rect DinoChar = {dino.x , dino.y + 15, 50, 90} ;
        SDL_Rect Enemy = {teemo.posX , teemo.posY + 10 , 80 , 100} ;
        check = SDL_HasIntersection(&DinoChar, &Enemy) ;
        return check ;
    }

    bool CheckTrap(Player dino, Fireball ball ){
        bool check=false;
        SDL_Rect DinoChar ={dino.x, dino.y,30,70};
        SDL_Rect Trap = {ball.x, ball.y, ball.w, ball.h};
        check=SDL_HasIntersection(&DinoChar, &Trap);
        return check;
    }
};


#endif // ENTITY_H
