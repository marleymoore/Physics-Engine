#include "game.h"
#include "Events.h"


Game::Game()
{
	m_view.setCenter(0.f, 0.f);
	m_view.setSize(m_worldSize);

	m_pWorld = new b2World(mk_gravity);

	m_debugDraw.setWorld(m_pWorld);


	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, 2.9f), sf::Vector2f(10.f, 0.2f), 0.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-3.9f, 0.f), sf::Vector2f(6.f, 0.2f), 90.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(3.9f, 0.f), sf::Vector2f(6.f, 0.2f), 90.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, 2.f), sf::Vector2f(3.f, 0.2f), 90.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-2.f, 2.f), sf::Vector2f(3.f, 0.2f), 90.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(2.f, 2.f), sf::Vector2f(3.f, 0.2f), 90.f));

	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, 0.5f), sf::Vector2f(0.2f, 0.2f), 45.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-2.f, 0.5f), sf::Vector2f(0.2f, 0.2f), 45.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(2.f, 0.5f), sf::Vector2f(0.2f, 0.2f), 45.f));

	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, -0.3f), sf::Vector2f(0.3f, 0.3f), 45.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-2.f, -0.3f), sf::Vector2f(0.3f, 0.3f), 45.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(2.f, -0.3f), sf::Vector2f(0.3f, 0.3f), 45.f));

	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(1.f, -1.f), sf::Vector2f(0.3f, 0.3f), 45.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-1.f, -1.f), sf::Vector2f(0.3f, 0.3f), 45.f));

	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, -1.6f), sf::Vector2f(0.3f, 0.3f), 45.f));


	m_balls.push_back(DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, -3.f), 0.15f, 0.f));
	m_balls.push_back(DynamicCircle(m_pWorld, sf::Vector2f(-0.85f, 1.6f), 0.1f, 0.f));

	ballSpawn = BallSpawn(sf::Vector2f(0.f, -2.5f), sf::Vector2f(8.f, 1.f));
}

Game::~Game()
{

	delete m_pWorld;
	m_pWorld = nullptr;
}

void Game::update(float timestep)
{

	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	for (DynamicCircle& ball : m_balls) ball.update();

	if (m_debug) m_debugDraw.clear();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

	target.setView(m_view);
	target.draw(ballSpawn);

	for (StaticBlock block : m_staticBlocks) target.draw(block);
	for (DynamicCircle ball : m_balls) target.draw(ball);


	if (m_debug) target.draw(m_debugDraw);
}


void Game::onMouseButtonClick(const sf::Vector2i& pixelCoords, const sf::Vector2f& viewCoords)
{
	sf::FloatRect ballSpawnBoundingBox = ballSpawn.getGlobalBounds();
	if (ballSpawnBoundingBox.contains(sf::Vector2f(viewCoords)))
	{
		m_balls.push_back(DynamicCircle(m_pWorld, sf::Vector2f(viewCoords), 0.2f, 0.f));
	}

}