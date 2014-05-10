#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionsManager.h"

class Game
{
public:
	Game();
	~Game(void);

	void createScene();

	void update();

	void run();
	
	void Event();

	void render();

private: 

	sf::RenderWindow window;
	sf::CircleShape ball;
	sf::RectangleShape joueur_1;
		
	sf::Vector2i mousePos;
	int mouseX ;
	int mouseY ;
	sf::Vector2f ballSpeed;
};

