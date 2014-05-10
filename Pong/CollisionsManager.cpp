#include "CollisionsManager.h"


CollisionsManager::CollisionsManager()
{
}

CollisionsManager::~CollisionsManager(void)
{
}


void CollisionsManager::playerCollisions(sf::RectangleShape rectangle, sf::CircleShape circle, sf::Vector2f ballSpeed)
{
	sf::FloatRect rectangleBox = rectangle.getGlobalBounds();
	sf::FloatRect circleBox = circle.getGlobalBounds();

	if (circleBox.intersects(rectangleBox))
	{
		ballSpeed.x= -ballSpeed.x;
		ballSpeed.y= (circleBox.top + circleBox.height/2 - rectangleBox.top - rectangleBox.height/2) / 100;
		int u = rectangleBox.left +  rectangleBox.width - circleBox.left;
		circleBox.left = rectangleBox.left +  rectangleBox.width + u;
		circle.setPosition(circleBox.left, rectangleBox.top);
		//increase ball speed by 1%
		ballSpeed.x=ballSpeed.x*1.01;
		ballSpeed.y=ballSpeed.y*1.01;
	}
}