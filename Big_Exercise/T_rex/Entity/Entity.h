#ifndef ENTITY_H
#define ENTITY_H


struct Entity {
	int x;
	int y;
	int w;
	int h;
    float dx; // tốc độ di chuyển theo chiều x
	float dy; //...chiều y
	int side;
	SDL_Texture *texture; //load ảnh

	bool collides(Entity* other) { //hàm va chạm với thực thể khác
	    return (max(x, other->x) < min(x + w, other->x + other->w))
	        && (max(y, other->y) < min(y + h, other->y + other->h));
	}

	void move() { //hàm di chuyển
	    x += dx;
	    y += dy;
	}

	bool offScreen() {
	     return x < -w || y < -h || x > SCREEN_WIDTH || y > SCREEN_HEIGHT;
	}
};



Entity player; // đặt tên struct người chơi
void doPlayer(){ // lấy hàm nhập phím để di chuyển
const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP] or currentKeyStates[SDL_SCANCODE_SPACE] or currentKeyStates[SDL_SCANCODE_W]) player.dy = -100;

        else if (currentKeyStates[SDL_SCANCODE_DOWN] or currentKeyStates[SDL_SCANCODE_S]){};

        else if (currentKeyStates[SDL_SCANCODE_LEFT] or currentKeyStates[SDL_SCANCODE_A]) player.dx = -30;

        else if (currentKeyStates[SDL_SCANCODE_RIGHT] or currentKeyStates[SDL_SCANCODE_D]) player.dx = 30;


        player.move();
dx =0;
dy = 0;
}

#endif // ENTITY_H
