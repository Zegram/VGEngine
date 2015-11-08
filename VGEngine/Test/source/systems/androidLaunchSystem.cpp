#include "systems\androidLaunchSystem.h"
#include "engine\input\mouse.h"
#include "engine\game\quadrangleComponent.h"
#include "engine\utility\logger.h"

using namespace vg;

AndroidLaunchSystem::AndroidLaunchSystem(Scene *scene)
{
	this->scene = scene;
	physicSystem = Game::getInstance()->getSceneManager()->getActiveScene()->getComponentSystemManager()->getSystem<PhysicsSystem>();

	core::AssetManager* assetManager = Game::getInstance()->getAssetManager();
	android = new GameObject("Android");
	TransformComponent *androidTransform = new TransformComponent(Vector2<float>(60, 60),
		Vector2<float>(32, 32), 0.0f, Vector2<float>(0, 0));
	android->addComponent(androidTransform);
	QuadrangleComponent *quadre = new QuadrangleComponent("android.png");
	android->addComponent(quadre);
	android->addComponent(new PhysicsCircleComponent(androidTransform, PhysicsComponent::DYNAMIC, 0));

	android->getComponent<PhysicsCircleComponent>()->setFriction(0.90);
	android->getComponent<PhysicsCircleComponent>()->setRestitution(0.60);
	android->getComponent<PhysicsCircleComponent>()->setDensity(100);

	scene->addGameObject(android);
}
AndroidLaunchSystem::~AndroidLaunchSystem()
{

}
void AndroidLaunchSystem::update(std::vector<vg::GameObject*> *gameObjects, float deltaTime)
{
#ifdef OS_WINDOWS
	if (vg::input::Mouse::isKeyPressed(vg::input::RIGHT))
	{	
		vg::Vector2<float> velocity = vg::input::Mouse::getPos() - android->getComponent<TransformComponent>()->getWorldPosition();
		android->getComponent<PhysicsCircleComponent>()->setVelocity(vg::Vector2<float>(velocity.getX(), velocity.getY()));
	}
#endif

#ifdef OS_ANROID

	if (vg::input::Touch::getIsTouched())
	{
		vg::Vector2<float> pos = vg::input::Touch::getPos();

		vg::Vector2<float> velocity = pos - android->getComponent<TransformComponent>()->getWorldPosition();
		android->getComponent<PhysicsCircleComponent>()->setVelocity(vg::Vector2<float>(velocity.getX(), velocity.getY()));
	}
#endif
}