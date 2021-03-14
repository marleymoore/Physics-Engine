
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "game.h"



void main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "CW Starter");
	Game game;


	float fFrameTime = 1.f / 60.f;


	sf::Clock clock;
	sf::Clock timer;

	while (window.isOpen())
	{



		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Tab)
				{
					game.toggleDebug();
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i pixelCoords(event.mouseButton.x, event.mouseButton.y);
				sf::Vector2f viewCoords = window.mapPixelToCoords(pixelCoords);
				game.onMouseButtonClick(pixelCoords, viewCoords);
			}
		}


		float m_fElapsedTime = clock.getElapsedTime().asSeconds();

		if (m_fElapsedTime > fFrameTime)
		{
			game.update(m_fElapsedTime);
			clock.restart();
		}


		window.clear(sf::Color(120, 120, 120));

		window.draw(game);
		window.display();

	}



}