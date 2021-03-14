#include "BallSpawn.h"

BallSpawn::BallSpawn()
{

}

BallSpawn::BallSpawn(const sf::Vector2f& position, const sf::Vector2f& size)
{
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setFillColor(sf::Color::Yellow);
	setOutlineThickness(0.f);
}