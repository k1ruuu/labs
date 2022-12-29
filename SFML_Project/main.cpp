#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace sf;
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

class player {
public:
	float x, y;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	player(Texture& image) {
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(0, 22, 16, 25));
		rect = FloatRect(40, 40, 16,25);
		x = y = 0;
		currentFrame = 0;
	}

	void update(float time) {
		rect.left += x * time;
		Collision(0);
		if (!onGround) {
			y += 0.001 * time;
		}
		rect.top += y * time;
		onGround = false;
		Collision(1);
		sprite.setPosition(rect.left- offsetX, rect.top- offsetY);

		currentFrame += 0.007;
		if (currentFrame > 5) currentFrame -= 5;

		if (x > 0) {
			sprite.setTextureRect(IntRect(17 * int(currentFrame), 211, 16, 25));
		}
		if (x < 0) {
			sprite.setTextureRect(IntRect(17 * int(currentFrame) + 17, 211, -16, 25));
		}
		x = 0;
	}
	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (Map[i][j] == 'B')
				{
					if ((x > 0) && (dir == 0)) 
						rect.left = j * 32 - rect.width;
					if ((x < 0) && (dir == 0)) 
						rect.left = j * 32 + 32;
					if ((y > 0) && (dir == 1)) { 
						rect.top = i * 32 - rect.height;
						y = 0;   
						onGround = true;
					}
					if ((y < 0) && (dir == 1)) { 
						rect.top = i * 32 + 32;   
						y = 0; }
				}

				if (Map[i][j] == '0')
				{
					Map[i][j] = ' ';
				}

			}

	}
};

int main()
{
	RenderWindow window(VideoMode(600, 600), "Test!");

	Texture p;
	p.loadFromFile("player.png");

	player player(p);

	Clock clock;

	RectangleShape rectangle(Vector2f(32, 32));
	

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 1000;

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.x = -0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.x = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (player.onGround) {
				player.y = -0.58;
				player.onGround = false;
			}
		}
		player.update(time);
		if (player.rect.left > 300) offsetX = player.rect.left - 600 / 2;
		offsetY = player.rect.top - 600 / 2;

		window.clear(Color::White);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (Map[i][j] == 'B') {
					rectangle.setFillColor(Color::Black);
				}


				if (Map[i][j] == '0') {
					rectangle.setFillColor(Color::Green);
				}

				if (Map[i][j] == ' ') continue;

				rectangle.setPosition(j * 32- offsetX, i * 32- offsetY);
				window.draw(rectangle);
			}
		}

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}




