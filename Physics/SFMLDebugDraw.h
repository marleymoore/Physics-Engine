#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class DebugDraw : public b2Draw {
private:
	std::vector<sf::VertexArray> m_shapes;
public:
	void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	void DrawTransform(const b2Transform& xf);

	std::vector<sf::VertexArray> getShapes() const { return m_shapes; };
	void clearShapes() { m_shapes.clear(); };
};

class SFMLDebugDraw : public sf::Drawable
{
private:
	b2World * m_pWorld = nullptr;
	DebugDraw m_debugDraw;
public:
	void setWorld(b2World * world);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void clear();
};

