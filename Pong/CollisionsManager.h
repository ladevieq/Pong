#pragma once
#include <SFML/Graphics.hpp>

class CollisionsManager
{
public:
	CollisionsManager(void);

	~CollisionsManager(void);

	void playerCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);

	void wallCollisions();
};

