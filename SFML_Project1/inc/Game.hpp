#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.cpp"

float offsetX = 0, offsetY = 0;
const int H = 12;
const int W = 40;


String Map[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                B     B",
"B                                B     B",
"B                                B     B",
"B                                B     B",
"B         0000                BBBB     B",
"B                                B     B",
"BBB                              B     B",
"B              BB                BB    B",
"B             BBB                      B",
"B    B       BBBB         BB           B",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};
using namespace std;
using namespace sf;

class Game {
public:
	void Run();
};


class player {
public:
	float x, y;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	player(Texture& image);

	void update(float time);
	void Collision(int dir);
};


