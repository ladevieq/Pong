#include "Game.h"

using namespace std;

Game::Game() : window(sf::VideoMode(1000, 800), "Pong", sf::Style::Default)
{
	window.setFramerateLimit(60);
	ballSpeed = sf::Vector2f(10, 1);
	mousePos = sf::Mouse::getPosition(window);
	mouseX = mousePos.x;
	mouseY = mousePos.y;
	moveDistance = 5;
	scoreJ1 = 0;
	scoreJ2 = 0;
	createScene();
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
			mouseX = event.mouseMove.x;
			mouseY = event.mouseMove.y;
			//cout << "X : " << mouseX << endl << "Y : " << mouseY << endl;
		}
	}
}

void Game::update()
{
	///////////
	//Player1//
	///////////
	if (mouseY > 650)
	{
		mouseY = 650;
	}
	else if (mouseY < 0)
	{
		mouseY = 0;
	}

	///////////
	//Player2//
	///////////
	if (ball.getPosition().y < joueur_2.getPosition().y)
	{
		joueur_2.move(0, -moveDistance/20.0);
	}
	else if(ball.getPosition().y + 12 > joueur_2.getPosition().y + joueur_2.getSize().y)
	{
		joueur_2.move(0, moveDistance/5.0);
	}

	ball.move(ballSpeed.x, ballSpeed.y);

	//////////////
	//Collisions//
	//////////////
	if (ball.getGlobalBounds().intersects(joueur_1.getGlobalBounds()))
	{
		ballSpeed = CollisionsManager::player_1Collisions(joueur_1, ball, ballSpeed);
	}
	if (ball.getGlobalBounds().intersects(joueur_2.getGlobalBounds()))
	{
		ballSpeed = CollisionsManager::player_2Collisions(joueur_2, ball, ballSpeed);
	}
	if(ball.getGlobalBounds().intersects(bord_haut.getGlobalBounds()))
	{
		ballSpeed = CollisionsManager::topWallCollisions(bord_haut, ball, ballSpeed);
	}
	if(ball.getGlobalBounds().intersects(bord_bas.getGlobalBounds()))
	{
		ballSpeed = CollisionsManager::topWallCollisions(bord_bas, ball, ballSpeed);
	}
	if (ball.getGlobalBounds().intersects(bord_gauche.getGlobalBounds()))
	{
		scoreJ2 ++;
		cout << "Score : " << scoreJ2 << endl;
		joueur_2.setPosition(950, 325);
		ball.setPosition(60, 375);
		ballSpeed = sf::Vector2f(10, 1);
	}
	if (ball.getGlobalBounds().intersects(bord_droite.getGlobalBounds()))
	{
		scoreJ1 ++;
		cout << "Score : " << scoreJ1 << endl;
		joueur_2.setPosition(950, 325);
		ball.setPosition(60, 375);
		ballSpeed = sf::Vector2f(10, 1);
	}
}

void Game::render()
{
	window.clear();
	draw();
	window.display();
}

void Game::createScene()
{
	/////////
	//Bords//
	/////////
	bord_haut = sf::RectangleShape(sf::Vector2f(1000, 1));
	bord_haut.setPosition(0, 0);
	bord_bas = sf::RectangleShape(sf::Vector2f(1000, 1));
	bord_bas.setPosition(0, 799);
	bord_gauche = sf::RectangleShape(sf::Vector2f(1, 800));
	bord_gauche.setPosition(0, 0);
	bord_droite = sf::RectangleShape(sf::Vector2f(1, 800));
	bord_droite.setPosition(999, 0);


	///////////
	//Joueurs//
	///////////
	joueur_1 = sf::RectangleShape(sf::Vector2f(10, 150));
	joueur_2 = sf::RectangleShape(sf::Vector2f(10, 150));
	joueur_2.setPosition(950, 325);


	/////////
	//Filet//
	/////////
	filet = sf::RectangleShape(sf::Vector2f(20, 800));
	filet.setPosition(490, 0);


	////////
	//Ball//
	////////
	ball = sf::CircleShape(12);
	ball.setPosition(60, 375);
	ball.setFillColor(sf::Color(255, 255, 0));


	////////////////////
	//Score////Joueur1//
	////////////////////
	cartoon.loadFromFile("from cartoon blocks.ttf");
	mJ1 [0].setFont(cartoon);
	mJ1 [0].setString("0");
	mJ1 [0].setCharacterSize(75);
	mJ1 [0].setColor(sf::Color::Red);
	mJ1 [0].setPosition(350, 10);

	mJ1 [1].setFont(cartoon);
	mJ1 [1].setString("1");
	mJ1 [1].setCharacterSize(75);
	mJ1 [1].setColor(sf::Color::Red);
	mJ1 [1].setPosition(350, 10);

	mJ1 [2].setFont(cartoon);
	mJ1 [2].setString("2");
	mJ1 [2].setCharacterSize(75);
	mJ1 [2].setColor(sf::Color::Red);
	mJ1 [2].setPosition(350, 10);

	mJ1 [3].setFont(cartoon);
	mJ1 [3].setString("3");
	mJ1 [3].setCharacterSize(75);
	mJ1 [3].setColor(sf::Color::Red);
	mJ1 [3].setPosition(350, 10);

	mJ1 [4].setFont(cartoon);
	mJ1 [4].setString("4");
	mJ1 [4].setCharacterSize(75);
	mJ1 [4].setColor(sf::Color::Red);
	mJ1 [4].setPosition(350, 10);

	mJ1 [5].setFont(cartoon);
	mJ1 [5].setString("5");
	mJ1 [5].setCharacterSize(75);
	mJ1 [5].setColor(sf::Color::Red);
	mJ1 [5].setPosition(350, 10);


	////////////////////
	//Score////Joueur2//
	////////////////////
	mJ2 [0].setFont(cartoon);
	mJ2 [0].setString("0");
	mJ2 [0].setCharacterSize(75);
	mJ2 [0].setColor(sf::Color::Red);
	mJ2 [0].setPosition(550, 10);

	mJ2 [1].setFont(cartoon);
	mJ2 [1].setString("1");
	mJ2 [1].setCharacterSize(75);
	mJ2 [1].setColor(sf::Color::Red);
	mJ2 [1].setPosition(550, 10);

	mJ2 [2].setFont(cartoon);
	mJ2 [2].setString("2");
	mJ2 [2].setCharacterSize(75);
	mJ2 [2].setColor(sf::Color::Red);
	mJ2 [2].setPosition(550, 10);

	mJ2 [3].setFont(cartoon);
	mJ2 [3].setString("3");
	mJ2 [3].setCharacterSize(75);
	mJ2 [3].setColor(sf::Color::Red);
	mJ2 [3].setPosition(550, 10);

	mJ2 [4].setFont(cartoon);
	mJ2 [4].setString("4");
	mJ2 [4].setCharacterSize(75);
	mJ2 [4].setColor(sf::Color::Red);
	mJ2 [4].setPosition(550, 10);

	mJ2 [5].setFont(cartoon);
	mJ2 [5].setString("5");
	mJ2 [5].setCharacterSize(75);
	mJ2 [5].setColor(sf::Color::Red);
	mJ2 [5].setPosition(550, 10);
}

void Game::draw()
{
	window.draw(bord_haut);
	window.draw(bord_bas);
	window.draw(bord_gauche);
	window.draw(bord_droite);
	window.draw(ball);
	window.draw(filet);
	joueur_1.setPosition(50, mouseY);
	window.draw(joueur_1);
	window.draw(joueur_2);

	////////////////////
	//Score////Joueur1//
	////////////////////
	if(scoreJ1 == 0)
	{
		window.draw(mJ1 [0]);
	}
	if(scoreJ1 == 1)
	{
		window.draw(mJ1 [1]);
	}
	if(scoreJ1 == 2)
	{
		window.draw(mJ1 [2]);
	}
	if(scoreJ1 == 3)
	{
		window.draw(mJ1 [3]);
	}
	if(scoreJ1 == 4)
	{
		window.draw(mJ1 [4]);
	}
	if(scoreJ1 == 5)
	{
		window.draw(mJ1 [5]);
	}

	////////////////////
	//Score////Joueur2//
	////////////////////
	if(scoreJ2 == 0)
	{
		window.draw(mJ2 [0]);
	}
	if(scoreJ2 == 1)
	{
		window.draw(mJ2 [1]);
	}
	if(scoreJ2 == 2)
	{
		window.draw(mJ2 [2]);
	}
	if(scoreJ2 == 3)
	{
		window.draw(mJ2 [3]);
	}
	if(scoreJ2 == 4)
	{
		window.draw(mJ2 [4]);
	}
	if(scoreJ2 == 5)
	{
		window.draw(mJ2 [5]);
	}
}
