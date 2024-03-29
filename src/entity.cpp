#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, Vector2f p_dim)
	: pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = (int)p_dim.x;
	currentFrame.h = (int)p_dim.y;
}

Vector2f& Entity::getPos()
{
	return pos;
}

SDL_Texture* Entity::getTexture()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

