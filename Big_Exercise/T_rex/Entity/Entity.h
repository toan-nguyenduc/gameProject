#ifndef ENTITY_H
#define ENTITY_H

#include "Player.h"
#include "Enemy.h"
#include "SDL.h"

struct Entity {
	bool CheckCollision(Player dino, Enemy teemo){
        bool check = false ;
        SDL_Rect DinoChar = {dino.x + 15, dino.y + 15, 60, 90} ;
        SDL_Rect Enemy = {teemo.posX + 10, teemo.posY + 10 , 80 , 100} ;
        check = SDL_HasIntersection(&DinoChar, &Enemy) ;
        return check ;
    }
};


#endif // ENTITY_H
