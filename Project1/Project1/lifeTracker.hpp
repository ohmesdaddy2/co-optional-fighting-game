#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class lifeTracker
{
	SDL_Renderer* screen;

	SDL_Rect coords;

	SDL_Rect healthCoords;

	short amount;

public:
	lifeTracker();
	~lifeTracker();

	bool setup(SDL_Renderer* passedScreen, int passedX, int passedY);

	void reduce(int damage);

	void render();
};

