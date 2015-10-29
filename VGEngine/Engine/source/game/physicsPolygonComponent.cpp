#include <engine\game\physicsPolygonComponent.h>
#include "engine\game\game.h"
#include "engine\game\physicsSystem.h"
#include "engine\game\scene.h"

using namespace vg;
PhysicsPolygonComponent::PhysicsPolygonComponent(TransformComponent *component, BODYTYPE type, float width, float height) : PhysicsComponent(component, type)
{
	PhysicsSystem *system = Game::getInstance()->getSceneManager()->getActiveScene()->getComponentSystemManager()->getSystem<PhysicsSystem>();

	float _width = 1;
	float _height = 1;

	if (width != 0 && height != 0)
	{
		_width = width;
		_height = height;
	}
	else
	{
		_width = component->getSize().getX();
		_height = component->getSize().getY();
	}

	float x = component->getWorldPosition().getX();
	float y = component->getWorldPosition().getY();
	
	b2BodyDef bodyDef;
	
	if (type == DYNAMIC)
	{
		bodyDef.type = b2BodyType::b2_dynamicBody;
	}
	else
		bodyDef.type = b2BodyType::b2_staticBody;

	mBoxShape.SetAsBox(_width / scale / 2.0f, _height / scale / 2.0f);

	_FixDef.density = 100.0f;
	_FixDef.shape = &mBoxShape;

	bodyDef.position = b2Vec2(x / scale, -y / scale);
	bodyDef.angle = 0.0f;

	_body = system->world->CreateBody(&bodyDef);
	_body->CreateFixture(&_FixDef);
}
