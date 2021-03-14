#pragma once
#include <SFML/Graphics.hpp>

class Events
{
public:

	virtual void onMouseButtonClick(const sf::Vector2i& pixelCoords, const sf::Vector2f& viewCoords) {};
};

