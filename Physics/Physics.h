#pragma once

#include <Box2D/Box2D.h>

#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

class Physics {
protected:
	b2Body * m_body = nullptr;
	const float mk_fDensity = 1.0f;
	const float mk_fFriction = 0.4f;
	const float mk_fRestitution = 0.6f;
};