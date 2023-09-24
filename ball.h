#ifndef BALL_H
#define BALL_H
#define PI 3.14159265358979323846
const int32_t WINDOW_WIDTH = 800; //â game
class Ball : public Entity //â ball
{
public:
	void setAngle(float angle)
	{
		this->angle = angle;
	}
	float getAngle()
	{
		return this->angle;
	}
	Ball(Texture& texture)
	{
		this->setPosition(BALL_INIT_POS);
		this->setAngle(PI / 2);
		this->setStatus(true);
		this->setTexture(texture);
		this->setScale(BALL_SCALE);
	}
	void checkWallCollision(Vector2f& new_offset_vector, float micro_step)
	{
		if (this->getPosition().y <= 0)
		{
			this->setAngle(-this->getAngle());
			new_offset_vector = PolarToDSC(micro_step, this->getAngle());
		}
		if (this->getPosition().x <= 0 || this->getPosition().x >= WINDOW_WIDTH)
		{
			this->setAngle(PI - this->getAngle());
			new_offset_vector = PolarToDSC(micro_step, this->getAngle());
		}
	}
	void checkPaddleCollision(FloatRect& paddle_bounds, Vector2f paddle_offset, Vector2f& new_offset_vector, float micro_step)
	{
		FloatRect ball_bounds = this->getGlobalBounds();
		FloatRect next_ball_bounds = MoveRect(ball_bounds, Vector2f(0.0f, -micro_step));
		if (ball_bounds.intersects(paddle_bounds) || next_ball_bounds.intersects(paddle_bounds))
		{
			Vector2f ball_offset = PolarToDSC(micro_step, -this->getAngle());
			new_offset_vector = VectorSum(ball_offset, paddle_offset);
			new_offset_vector = ScalingVector(new_offset_vector, micro_step / Absolute(new_offset_vector));
			this->setAngle(PI + atan(new_offset_vector.y / new_offset_vector.x));
		}
		else new_offset_vector = PolarToDSC(micro_step, this->getAngle());
	}
	void checkBricksCollision(vector<Brick>& BricksList, Vector2f new_offset_vector, float micro_step)
	{
		FloatRect ball_bounds = this->getGlobalBounds();
		FloatRect next_ball_bounds = MoveRect(ball_bounds, PolarToDSC(micro_step, this->getAngle()));
		for (Brick& brick : BricksList)
		{
			if (next_ball_bounds.intersects(brick.getGlobalBounds()) && brick.getStatus())
			{
				brick.changeStatus();
				this->setAngle(PI + atan(new_offset_vector.y / new_offset_vector.x));
			}
		}
	}
	void updateBall(Paddle& paddle, float elapsed_time, Vector2f paddle_offset, std::vector<Brick>& BricksList)
	{
		FloatRect ball_bounds = this->getGlobalBounds();
		FloatRect paddle_bounds = paddle.getGlobalBounds();
		float micro_step = BALL_SPEED * elapsed_time;
		FloatRect next_ball_bounds = MoveRect(ball_bounds, Vector2f(0.0f, -micro_step));
		Vector2f new_offset_vector = ZERO_VECTOR;
		checkPaddleCollision(paddle_bounds, paddle_offset, new_offset_vector, micro_step);
		checkWallCollision(new_offset_vector, micro_step);
		checkBricksCollision(BricksList, new_offset_vector, micro_step);
		this->move(new_offset_vector);
	}
private:
	float angle;
};
#endif