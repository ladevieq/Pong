#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CollisionsManager
{
public:
	CollisionsManager();

	~CollisionsManager(void);

	static sf::Vector2f player_1Collisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);
	
	static sf::Vector2f player_2Collisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);

	static sf::Vector2f  topWallCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);

	static sf::Vector2f  botWallCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed);

private:

	sf::RectangleShape rectangle;

	sf::CircleShape circle;

	sf::Vector2f ballSpeed;
};

