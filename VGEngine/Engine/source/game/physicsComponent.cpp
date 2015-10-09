#include "engine\game\physicsComponent.h"

using namespace vg;

PhysicsComponent::PhysicsComponent(float x, float y, float width, float height, b2BodyType type, b2World *world)
{
	b2PolygonShape shape;
	b2BodyDef bodyDef;

	shape.SetAsBox(width / 2, height / 2);

	b2FixtureDef FixDef;
	FixDef.density = 1.0f;
	FixDef.friction = 1.0f;
	FixDef.restitution = 1.0f;
	FixDef.shape = &shape;

	bodyDef.position = b2Vec2(x, -y);
	bodyDef.angle = 0.0f;
	bodyDef.type = type;
	
	_body = world->CreateBody(&bodyDef);
	_body->CreateFixture(&FixDef);
}

PhysicsComponent::PhysicsComponent(float x, float y, float radius, b2BodyType type, b2World *world)
{
	b2BodyDef bodyDef;

	b2CircleShape circle;
	circle.m_p.Set(x, -y);
	circle.m_radius = radius / 2;

	b2FixtureDef FixDef;
	FixDef.density = 10.0f;
	FixDef.friction = 1.0f;
	FixDef.shape = &circle;

	bodyDef.position = b2Vec2(x, -y);
	bodyDef.angle = 0.0f;
	bodyDef.type = type;

	_body = world->CreateBody(&bodyDef);
	_body->CreateFixture(&FixDef);
}