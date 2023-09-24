#include "bonus.h"
#include "game.h"
#include <iostream>

void Bonus::setBonusType(BonusType bonus_type)
{
	this->bonus_type = bonus_type;
}
BonusType Bonus::getBonusType()
{
	return this->bonus_type;
}
void Bonus::setActivated(bool activated)
{
	this->activated = activated;
}
bool Bonus::getActivated()
{
	return this->activated;
}


Bonus::Bonus(Vector2f position)
{

	srand(time(0));
	int32_t bonus_type;
	bonus_type =  rand() % 8;
	switch (bonus_type)
	{
	case 0:
	{
		BONUS_TEXTURE.loadFromFile("images/bonus_extrascores.png");
		this->setBonusType(BonusType::EXTRASCORES);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 1:
	{ BONUS_TEXTURE.loadFromFile("images/bonus_redutio.png");
		this->setBonusType(BonusType::REDUCE_PADDLE);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 2:
	{ BONUS_TEXTURE.loadFromFile("images/bonus_engorgio.png");
		this->setBonusType(BonusType::INCREASE_PADDLE);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 3:
	{BONUS_TEXTURE.loadFromFile("images/bonus_extralife.png");
		this->setBonusType(BonusType::EXTRALIFE);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 4:
	{BONUS_TEXTURE.loadFromFile("images/bonus_allpervading.png");
		this->setBonusType(BonusType::ALLPERVADING);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	
	case 5:
	{ BONUS_TEXTURE.loadFromFile("images/bonus_increase_ball_speed-transformed.png");
		this->setBonusType(BonusType::INCREASE_BALL_SPEED);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 6:
	{BONUS_TEXTURE.loadFromFile("images/bonus_randomize_angle-transformed.png");
		this->setBonusType(BonusType::RANDOMIZE_ANGLE);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	case 7:
	{BONUS_TEXTURE.loadFromFile("images/bonus_bottom_paddle.png");
		this->setBonusType(BonusType::BOTTOM_AS_PADDLE);
		this->setStatus(true);
		this->setTexture(BONUS_TEXTURE);
		this->setActivated(false);
		break;
	}
	}
	this->setScale(Vector2f(0.2f, 0.2f));
	this->setPosition(position);
	Clock clock;
	this->bonus_clock = clock;
}

void Bonus::BonusDeactivate(Game& game, Ball& ball, Paddle& paddle)
{
	if (this->getBonusType() == BonusType::ALLPERVADING) game.setAP(false);
	if (this->getBonusType() == BonusType::INCREASE_PADDLE
		|| this->getBonusType() == BonusType::REDUCE_PADDLE)
		paddle.setScale(1.f, 1.f);

}
void Bonus::bonusCollidesPaddle(Paddle& paddle)
{
	FloatRect bonusbounds = this->getGlobalBounds();
	FloatRect paddleBounds = paddle.getGlobalBounds();
	if (bonusbounds.intersects(paddleBounds)) {
		this->setActivated(true);
		this->move(-1000, -1000);
	}
}
void Bonus::bonusMoving(float elapsed_time)
{
	float micro_step = BONUS_SPEED * elapsed_time;
	this->move(Vector2f(0.f, micro_step));
	
}

void Bonus::updateByTime(Game& game, Ball& ball, Paddle& paddle)
{
	float elapsed_time = this->bonus_clock.getElapsedTime().asSeconds();
	if (elapsed_time >= 15.f)
	{
		this->BonusDeactivate(game, ball, paddle);
		this->setStatus(false);
	}
}

void UpdateBonusList(std::vector<Bonus>& BonusList, float elapsed_time,
	Paddle& paddle, Game& game, Ball& ball)
{

	for (auto& bonus : BonusList)
	{
		if (bonus.getStatus())
		{
			bonus.bonusCollidesPaddle(paddle);
			bonus.bonusMoving(elapsed_time);

			bonus.updateByTime(game, ball, paddle);
		}
	}
}

void DrawBonuses(RenderWindow& window, std::vector<Bonus>& BonusList)
{
	for (auto& bonus : BonusList) if (bonus.getStatus() && !bonus.getActivated()) window.draw(bonus);
}