#pragma once
#include <SFML/Graphics.hpp>

class CollisionsManager
{
public:
	CollisionsManager();

	~CollisionsManager(void);

	static void playerCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);

//	void wallCollisions();

private:

	sf::RectangleShape rectangle;

	sf::CircleShape circle;

	sf::Vector2f ballSpeed;
};

