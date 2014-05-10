#include "Game.h"


Game::Game() : window(sf::VideoMode(1000, 800), "Pong", sf::Style::Default)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	int mouseX = mousePos.x;
	int mouseY = mousePos.y;
	sf::Vector2f ballSpeed(0.1,0.1);

	sf::CircleShape ball (12);
	ball.setPosition(60, 475);
	ball.setFillColor(sf::Color(255, 255, 0));
	sf::RectangleShape joueur_1(sf::Vector2f(10, 150));
	joueur_1.setPosition(50, mouseY);
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

void Game::createScene()
{
	if (mouseY > 650)
	{
		mouseY = 650;
	}

	else if (mouseY < 0)
	{
		mouseY = 0;
	}

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

	joueur_1.setPosition(50, mouseY);
	sf::RectangleShape joueur_2(sf::Vector2f(10, 150));
	joueur_2.setPosition(950, 350);
	sf::RectangleShape filet (sf::Vector2f(20, 800));
	filet.setPosition(490, 0);

	window.draw(ball);
	window.draw(filet);
	window.draw(joueur_1);
	window.draw(joueur_2); 
}

void Game::update()
{
	ball.move(ballSpeed.x,ballSpeed.y);
	CollisionsManager::playerCollisions(joueur_1, ball, ballSpeed);
}

void Game::render()
{
	window.clear();
	createScene();
	window.display();
}