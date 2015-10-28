
#include "engine/game/physicsSystem.h"
#include "engine/game/physicsPolygonComponent.h"
#include "engine/game/physicsComponent.h"

#include <typeinfo>
#include <vector>

using namespace vg;

b2World *PhysicsSystem::world = nullptr;
float scale = PhysicsComponent::scale;

PhysicsSystem::PhysicsSystem(float gravityX, float gravityY)
{
	b2Vec2 *b2Gravity = new b2Vec2(gravityX, gravityY);
	world = new b2World(*b2Gravity);
	world->SetGravity(*b2Gravity);
}

PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::update(std::vector<GameObject*> *gameObjects, float deltaTime)
{
	 int velocityIterations = 8;
	 int positionIterations = 3;

	 world->Step(deltaTime, velocityIterations, positionIterations);

	 for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	 {
		 PhysicsComponent* physComponent = nullptr;
		 TransformComponent* transform = (*it)->getComponent<TransformComponent>();

		 auto *components = (*it)->getAllComponents();
		 for (std::unordered_map<const std::type_info*, Component*>::iterator ij = components->begin(); ij != components->end(); ij++)
		 {
			 if (dynamic_cast<PhysicsComponent*>(ij->second) != nullptr)
			 {
				 physComponent = dynamic_cast<PhysicsComponent*>(ij->second);
				 break;
			 }
		 }

		 if (physComponent != nullptr && transform != nullptr)
		 {
			 transform->setPosition(Vector2<float>((physComponent->getBody()->GetPosition().x  * scale) - transform->getSize().getX() / 2.0f, 
												(-physComponent->getBody()->GetPosition().y * scale) - transform->getSize().getY() / 2.0f));
			  transform->setRotation(-1.0f * physComponent->getBody()->GetAngle() * 180 / 3.14);
			  
		 }
	 }
}

void PhysicsSystem::createBorders(float x, float y, float width, float height)
{
	b2Vec2 vs[5];
	b2Body *boundaries;

	vs[0].Set(x, y);
	vs[1].Set(x, -height / scale);
	vs[2].Set(width / scale, -height / scale);
	vs[3].Set(width / scale, y);
	vs[4].Set(x, y);
	
	b2ChainShape chain;
	b2BodyDef chainDef;
	b2FixtureDef chainFix;

	chain.CreateChain(vs, 5);
	chainFix.shape = &chain;

	boundaries = world->CreateBody(&chainDef);
	boundaries->CreateFixture(&chainFix);
}