
#include "engine/game/scene.h"
#include "engine/game/transformComponent.h"

#include <algorithm>

using namespace vg;

Scene::Scene()
	:paused(false)
{
	mSystemManager = SystemManager();
}
Scene::~Scene()
{
	clearObjects();
}

void Scene::addGameObject(GameObject *gObject)
{
	mActivePool.push_back(gObject);
}

void Scene::add(GameObject* obj)
{
	mActivePool.push_back(obj);
}

void Scene::updateGameObjects(float deltaTime)
{
	sortActivePool();
	mSystemManager.update(&mActivePool, deltaTime);
}

void Scene::sortActivePool()
{
	sort(mActivePool.begin(), mActivePool.end(),
		[](GameObject* a, GameObject* b)-> bool
	{
		TransformComponent* transformA = a->getComponent<TransformComponent>();
		TransformComponent* transformB = b->getComponent<TransformComponent>();
		float layerA = -1.0f;
		float layerB = -1.0f;
		if (transformA != nullptr)
			layerA = transformA->getLayer();
		if (transformB != nullptr)
			layerB = transformB->getLayer();
		return layerA < layerB;
	});
}
void Scene::clearObjects()
{
	for (auto it = mActivePool.begin(); it != mActivePool.end(); it++)
	{
		delete (*it);
	}

	mActivePool.clear();

}
void Scene::clearSystems()
{
	mSystemManager.clearSystems();
	mSystemManager.addDefaultSystems();
}