#ifndef GAME_H
#define GAME_H
#include "brick.h"
#include "paddle.h"
#include "ball.h"

#include <vector>



const int32_t WINDOW_HEIGHT = 600; //â game






void CheckForWindowClosed(Event& event, RenderWindow& window) //â game
{
	while (window.pollEvent(event))
		if (event.type == Event::Closed) window.close();
}

void UpdateScene(Clock& clock, Paddle& paddle, Ball& ball, vector<Brick>& BricksList) //game
{
	float elapsed_time = clock.getElapsedTime().asSeconds();
	clock.restart();
	paddle.updateDirection();
	ball.updateBall(paddle, elapsed_time,
		paddle.updatePaddle(elapsed_time), BricksList);
}

void DrawScene(RenderWindow& window, Ball& ball, Paddle& paddle, std::vector<Brick>& BricksList) //game
{
	window.clear();
	window.draw(paddle);
	window.draw(ball);
	DrawBricks(window, BricksList);
	window.display();
}


#endif