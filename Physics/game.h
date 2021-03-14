#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "staticBlock.h"
#include "dynamicCircle.h"
#include "Events.h"
#include "BallSpawn.h"
#include "SFMLDebugDraw.h"




class Game : public sf::Drawable, public Events {
private:
	sf::View m_view;
	sf::Vector2f m_worldSize = sf::Vector2f(8.f, 6.f);

	b2World* m_pWorld = nullptr;
	const int mk_iVelIterations = 7;
	const int mk_iPosIterations = 5;
	const b2Vec2 mk_gravity = b2Vec2(0.f, 9.81f);

	std::vector<StaticBlock> m_staticBlocks;
	std::vector<DynamicCircle> m_balls;
	BallSpawn ballSpawn;

	bool m_debug = false;
	SFMLDebugDraw m_debugDraw;
public:
	Game();
	~Game();
	void update(float timestep);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void toggleDebug() { m_debug = !m_debug; }
	virtual void onMouseButtonClick(const sf::Vector2i& pixelCoords, const sf::Vector2f& viewCoords) override;
};