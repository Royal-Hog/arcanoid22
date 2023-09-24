#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

enum struct Direct { NONEDIR, UP, DOWN, LEFT, RIGHT };
const Vector2f ZERO_VECTOR = Vector2f(0.0f, 0.0f);
class Paddle : public Entity //â paddle
{
public:
	void setDirection(Direct direction)
	{
		this->direction = direction;
	}
	Direct getDirection()
	{
		return this->direction;
	}
	Paddle(Texture& texture)
	{
		this->setPosition(PADDLE_INIT_POS);
		this->setDirection(Direct::NONEDIR);
		this->setStatus(true);
		this->setTexture(texture);
	}
	void updateDirection()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) this->setDirection(Direct::LEFT);
		if (Keyboard::isKeyPressed(Keyboard::Right)) this->setDirection(Direct::RIGHT);
	}
	Vector2f updatePaddle(float elapsed_time)
	{
		float absolute_offset = PADDLE_SPEED * elapsed_time;
		Vector2f offset = ZERO_VECTOR;
		if (this->getDirection() == Direct::LEFT) offset = Vector2f(-absolute_offset, 0.0f);
		if (this->getDirection() == Direct::RIGHT) offset = Vector2f(absolute_offset, 0.0f);
		this->move(offset);
		this->setDirection(Direct::NONEDIR);
		return offset;
	}
private:
	Direct direction;
};
#endif 