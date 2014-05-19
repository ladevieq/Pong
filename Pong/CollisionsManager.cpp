#include "CollisionsManager.h"

using namespace std;

CollisionsManager::CollisionsManager()
{
}

CollisionsManager::~CollisionsManager(void)
{
}

sf::Vector2f CollisionsManager::player_1Collisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed)
{
	sf::FloatRect circleBox = circle.getGlobalBounds();

	ballSpeed.x =- ballSpeed.x;
	ballSpeed.y= (circleBox.top + circleBox.height/2 - rectangle.getGlobalBounds().top - rectangle.getGlobalBounds().height/2) / 100;
	int u = circleBox.left + circleBox.width - rectangle.getGlobalBounds().left;
	circleBox.left = rectangle.getGlobalBounds().left +  circleBox.width + u;
	circle.setPosition(circleBox.left, circleBox.top);
	//increase ball speed by 1%
	ballSpeed.x = ballSpeed.x*1.01;
	ballSpeed.y = ballSpeed.y*1.01;
	return ballSpeed;
}

sf::Vector2f CollisionsManager::player_2Collisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed)
{
	sf::FloatRect circleBox = circle.getGlobalBounds();

	ballSpeed.x =- ballSpeed.x;
	ballSpeed.y= (circleBox.top + circleBox.height/2 - rectangle.getGlobalBounds().top - rectangle.getGlobalBounds().height/2) / 100;
	int u = circleBox.left + circleBox.width - rectangle.getGlobalBounds().left;
	circleBox.left = rectangle.getGlobalBounds().left -  circleBox.width - u;
	circle.setPosition(circleBox.left, circleBox.top);
	//increase ball speed by 1%
	ballSpeed.x = ballSpeed.x*1.01;
	ballSpeed.y = ballSpeed.y*1.01;
	return ballSpeed;
}

sf::Vector2f  CollisionsManager::topWallCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed)
{
	ballSpeed.y=-ballSpeed.y;
	int u = rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height - circle.getGlobalBounds().top;
	circle.move(0,2*u);            
	return ballSpeed;
}

sf::Vector2f  botWallCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed)
{
	ballSpeed.y=-ballSpeed.y;
	int u = rectangle.getGlobalBounds().top - rectangle.getGlobalBounds().height + circle.getGlobalBounds().top;
	circle.move(0,2*u);            
	return ballSpeed;
}