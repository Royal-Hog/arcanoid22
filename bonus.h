#ifndef BONUS_H
#define BONUS_H
#include "entity.h"
#include <random>
class Game;
class Ball;
class Paddle;

enum struct BonusType {
	EXTRASCORES, REDUCE_PADDLE,
	INCREASE_PADDLE, EXTRALIFE, ALLPERVADING,
 INCREASE_BALL_SPEED, RANDOMIZE_ANGLE, BOTTOM_AS_PADDLE
};

const float BONUS_SPEED = 100.f;
class Bonus : public Entity
{
private:
	BonusType bonus_type;
	Clock bonus_clock;
	bool activated;
public:
	void setBonusType(BonusType bonus_type);
	BonusType getBonusType();
	void setActivated(bool activated);
	bool getActivated();
	Bonus();
	Bonus(Vector2f position);

	void BonusDeactivate(Game& game, Ball& ball, Paddle& paddle);
	void bonusCollidesPaddle(Paddle& paddle);
	void bonusMoving(float elapsed_time);

	void updateByTime(Game& game, Ball& ball, Paddle& paddle);
};

void UpdateBonusList(std::vector<Bonus>& BonusList, float elapsed_time,
	Paddle& paddle, Game& game, Ball& ball);

void DrawBonuses(RenderWindow& window, std::vector<Bonus>& BonusList);
#endif