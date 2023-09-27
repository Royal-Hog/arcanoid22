#include <SFML/Graphics.hpp>
#include <vector>
#include "vector_extra_func.h"
#include "game.h"
#include "entity.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#define PI 3.14159265358979323846

int32_t main(const int32_t argc, const char* const argv)
{
	Game game;
	initGame(game);
	return EXIT_SUCCESS;
}