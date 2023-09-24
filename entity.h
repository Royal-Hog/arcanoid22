#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
using namespace sf;
Texture BALL_TEXTURE; //� entity
Texture PADDLE_TEXTURE; //� entity
Texture BRICK_TEXTURE; //� entity

const Vector2f PADDLE_INIT_POS = Vector2f(400, 550); //� entity
const float PADDLE_SPEED = 48.0f; //� entity

const Vector2f BALL_INIT_POS = Vector2f(400, 300); //� entity
const Vector2f BALL_SCALE = Vector2f(0.1f, 0.1f); //� entity
const float BALL_SPEED = 32.0f; //� entity

const Vector2f FIRST_BRICK_POS = Vector2f(0, 100); //� entity
const Vector2f BRICK_SIZE = Vector2f(75.f, 25.f); //� entity

class Entity : public Sprite //� entity
{
public:
	bool Colliding(FloatRect& rect)
	{
		return this->getGlobalBounds().intersects(rect);
	}
	void setStatus(bool status)
	{
		this->is_existing = status;
	}
	void changeStatus()
	{
		this->is_existing = !this->is_existing;
	}
	bool getStatus()
	{
		return this->is_existing;
	}
private:
	bool is_existing;
};

static const sf::FloatRect MoveRect(const sf::FloatRect& my_rect, sf::Vector2f offset) //� entity
{
	return { my_rect.left + offset.x, my_rect.top + offset.y, my_rect.width, my_rect.height };
}
#endif