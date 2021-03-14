
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#pragma
#include "Physics.h"


class DynamicCircle : public sf::CircleShape, public Physics
{
private:
public:
	DynamicCircle();
	DynamicCircle(b2World * world, const sf::Vector2f& position, const float radius, const float orientation);
	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
