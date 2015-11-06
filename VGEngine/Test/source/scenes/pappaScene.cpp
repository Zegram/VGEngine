
#include "scenes/pappaScene.h"

#include "engine/game/transformComponent.h"
#include "engine/game/quadrangleComponent.h"
#include "systems/sceneChangeSystem.h"
#include "engine/game/animationComponent.h"
#include "engine/game/textComponent.h"
#include "engine/game/game.h"

#include "systems\PhysicsTestSystem.h"

using namespace vg;

PappaScene::PappaScene()
{
}

PappaScene::~PappaScene()
{
}

void PappaScene::loadObjects()
{
	core::AssetManager* assetManager = Game::getInstance()->getAssetManager();

	// Background
	GameObject *background = new GameObject("background");
	TransformComponent *backgroundTransform = new TransformComponent(Vector2<float>(0, 0),
		Vector2<float>(1280, 720), 0.0f);
	background->addComponent(backgroundTransform);
	QuadrangleComponent *quadrBackground = new QuadrangleComponent("muumiBG.png");
	background->addComponent(quadrBackground);
	addGameObject(background);

	// Physics system
	PhysicsTestSystem *fysiks = new PhysicsTestSystem(this);
	Game::getInstance()->addComponentSystem(this, fysiks);

	
	// sound
	assetManager->load<sound::Sound>("muumitechno.mp3");
	Game::getInstance()->getAudioManager()->addSound("music",
		*assetManager->get<sound::Sound>("muumitechno.mp3"));
	Game::getInstance()->getAudioManager()->play("music");
	Game::getInstance()->getAudioManager()->loopEnabled("music", true);

	// Scene change system
	sceneChangeSystem *sceneChange = new sceneChangeSystem(this);
	Game::getInstance()->addComponentSystem(this, sceneChange);
}