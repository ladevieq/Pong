#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;

void collision(sf::RectangleShape &rectangle, sf::CircleShape &circle, sf::Vector2f &speed)
{
	sf::FloatRect rectangleBox = rectangle.getGlobalBounds();
	sf::FloatRect circleBox = circle.getGlobalBounds();

	if (rectangleBox.intersects(circleBox))
	{
		speed.y=-speed.y;
        int u = rectangleBox.top + rectangleBox.height - circleBox.top;
		circle.move(0,2*u);
	}
}


int main()
{
	Game pong;
	pong.run();
}