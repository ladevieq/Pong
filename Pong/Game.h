#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionsManager.h"
#include <iostream>

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

	void draw();

private: 

	sf::RectangleShape bord_haut;
	sf::RectangleShape bord_bas;
	sf::RectangleShape bord_gauche;
	sf::RectangleShape bord_droite;
	sf::CircleShape ball;
	sf::RectangleShape joueur_1;
	sf::RectangleShape joueur_2;
	sf::RectangleShape filet;
	sf::RenderWindow window;

	sf::Vector2i mousePos;
	sf::Vector2f ballSpeed;
	int mouseX ;
	int mouseY ;
	int moveDistance;
	int scoreJ1;
	int scoreJ2;

	/////////
	//Score//
	/////////
	sf::Font cartoon;
	sf::Text mJ1 [5];
	sf::Text mJ2 [5];
};

