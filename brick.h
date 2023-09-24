#ifndef BRICK_H
#define BRICK_H
#include "entity.h"

const float BRICKS_GAP = 5.f;
int32_t ROWS = 3; //â game
int32_t BRICKS_IN_ROW = 10; //â game

class Brick : public Entity //â brick
{
public:
	Brick(Vector2f position, Texture& texture)
	{
		this->setPosition(position);
		this->setStatus(true);
		this->setTexture(texture);
	}
private:
};

std::vector<Brick> InitBricksList() //â game
{
	vector<Brick> BricksList;
	float iterator_x = FIRST_BRICK_POS.x;
	float iterator_y = FIRST_BRICK_POS.y;
	for (size_t y = 1; y <= ROWS; y++)
		for (size_t x = 0; x < BRICKS_IN_ROW; x++)
			BricksList.push_back(Brick(Vector2f(x * (BRICK_SIZE.x + BRICKS_GAP),
				y * (BRICK_SIZE.y + BRICKS_GAP)), BRICK_TEXTURE));
	return BricksList;
}

void DrawBricks(RenderWindow& window, vector<Brick>& BricksList) //â game
{
	for (Brick& brick : BricksList) if (brick.getStatus()) window.draw(brick);
}
#endif