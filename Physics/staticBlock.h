#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Physics.h"



class StaticBlock : public sf::RectangleShape, public Physics
{
public:
	StaticBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation);
};
