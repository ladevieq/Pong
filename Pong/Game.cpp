#include "Game.h"

using namespace std;

Game::Game() : window(sf::VideoMode(1000, 800), "Pong", sf::Style::Default)
{
//	sf::CircleShape ball (12);
//	sf::RectangleShape joueur_1 (sf::Vector2f(10, 150));
	sf::Vector2f ballSpeed(0.1,0.1);
}

Game::~Game(void)
{
}

void Game::run()
{
	while (window.isOpen())
	{
		Event();
		update();
		render();
	}
}

void Game::Event()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		if (event.type == sf::Event::MouseMoved)
		{
			int mouseX = event.mouseMove.x;
			int mouseY = event.mouseMove.y;
			//cout << "X : " << mouseX << endl << "Y : " << mouseY << endl;
		}
	}
}

void Game::update()
{
	mousePos = sf::Mouse::getPosition(window);
	mouseX = mousePos.x;
	mouseY = mousePos.y;

	if (mouseY > 650)
	{
		mouseY = 650;
	}

	else if (mouseY < 0)
	{
		mouseY = 0;
	}
	ball.move(ballSpeed.x,ballSpeed.y);
	CollisionsManager::playerCollisions(joueur_1, ball, ballSpeed);
}

void Game::render()
{
	window.clear();
	createScene();
	window.display();
}

void Game::createScene()
{
	/////////
	//Bords//
	/////////
	sf::RectangleShape bord_haut (sf::Vector2f(1000, 1));
	bord_haut.setPosition(0, 0);
	window.draw(bord_haut);
	sf::RectangleShape bord_bas (sf::Vector2f(1000, 1));
	bord_bas.setPosition(0, 799);
	window.draw(bord_bas);
	sf::RectangleShape bord_gauche (sf::Vector2f(1, 800));
	bord_gauche.setPosition(0, 0);
	window.draw(bord_gauche);
	sf::RectangleShape bord_droite (sf::Vector2f(1, 800));
	bord_droite.setPosition(999, 0);
	window.draw(bord_droite);
	
	//Joueurs
	sf::RectangleShape joueur_1 (sf::Vector2f(10, 150));
	joueur_1.setPosition(50, mouseY);
	sf::RectangleShape joueur_2(sf::Vector2f(10, 150));
	joueur_2.setPosition(950, 350);

	//Filet
	sf::RectangleShape filet (sf::Vector2f(20, 800));
	filet.setPosition(490, 0);


	//Ball
	sf::CircleShape ball (12);
	ball.setPosition(60, 475);
	ball.setFillColor(sf::Color(255, 255, 0));

	window.draw(ball);
	window.draw(filet);
	window.draw(joueur_1);
	window.draw(joueur_2); 
}