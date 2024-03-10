#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* bunkerTexture = window.loadTexture("res/gfx/Bunker.png");
	
	std::vector<Entity> entities = {
		// Entity(Vector2f(139, 320), bunkerTexture, Vector2f(42, 32)),
		Entity(Vector2f(812, 320), bunkerTexture, Vector2f(42, 32)),
		// Entity(Vector2f(296, 320), bunkerTexture, Vector2f(42, 32)),
		// Entity(Vector2f(396, 320), bunkerTexture, Vector2f(42, 32))
	};

	// 360 64

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning) {
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}

		window.clear();

		for (Entity& e: entities) {
			window.render(e);
		}

		window.display();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}