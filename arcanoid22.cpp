#include <SFML/Graphics.hpp>
#include <vector>
#include "vector_extra_func.h"
#include "game.h"
#include "entity.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#define PI 3.14159265358979323846

using namespace std;
using namespace sf;




int32_t main(const int32_t argc, const char* const argv) //внутренности в game
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ARCANOID");
	window.setFramerateLimit(60);
	if (!BALL_TEXTURE.loadFromFile("images/ball_tmp-transformed.png")
		|| !BRICK_TEXTURE.loadFromFile("images/brick_texture.png")
		|| !PADDLE_TEXTURE.loadFromFile("images/paddle_texture.png"))
		return EXIT_FAILURE;
	Paddle paddle = Paddle(PADDLE_TEXTURE);
	Ball ball = Ball(BALL_TEXTURE);
	Clock clock;
	std::vector<Brick> BricksList = InitBricksList();
	while (window.isOpen())
	{
		sf::Event event;
		CheckForWindowClosed(event, window);
		UpdateScene(clock, paddle, ball, BricksList);
		DrawScene(window, ball, paddle, BricksList);
	}
	return EXIT_SUCCESS;
}