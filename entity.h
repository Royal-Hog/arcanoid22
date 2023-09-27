#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
using namespace sf;
static Texture BALL_TEXTURE;
static Texture PADDLE_TEXTURE;
static Texture BRICK_TEXTURE_1;
static Texture BRICK_TEXTURE_2;
static Texture BRICK_TEXTURE_3;
static Texture BRICK_TEXTURE_4;
static Texture BRICK_TEXTURE_5;

static Texture BONUS_TEXTURE;

const Vector2f BALL_INIT_POS = Vector2f(400, 300); //� entity
const Vector2f BALL_SCALE = Vector2f(0.1f, 0.1f); //� entity
const float BALL_SPEED = 32.0f; //� entity



extern Vector2f PADDLE_INIT_POS;
extern float PADDLE_SPEED;

extern Vector2f BALL_INIT_POS;
extern Vector2f BALL_SCALE;
extern float BALL_SPEED;

extern Vector2f FIRST_BRICK_POS;
extern Vector2f BRICK_SIZE;

class Entity : public Sprite
{
public:
	bool Colliding(FloatRect& rect);
	void setStatus(bool status);
	void changeStatus();
	bool getStatus();
private:
	bool is_existing;
};

static const sf::FloatRect MoveRect(const sf::FloatRect& my_rect, sf::Vector2f offset)
{
	return { my_rect.left + offset.x, my_rect.top + offset.y, my_rect.width, my_rect.height };
}
#endif