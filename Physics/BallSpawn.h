#pragma once
#include <SFML/Graphics.hpp>

class BallSpawn : public sf::RectangleShape
{
public:
	BallSpawn();
	BallSpawn(const sf::Vector2f& position, const sf::Vector2f& size);

};

