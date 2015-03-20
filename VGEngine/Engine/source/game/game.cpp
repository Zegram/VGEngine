
#include "engine/game.h"
#include "engine/utility/logger.h"
#include "engine/input/input.h"

using namespace vg;
Game* Game::gameInstance;
Game::Game(Graphics* graphics)
    : mPulse(0), mIsRunning(true)
{
    testSprite = DebugSprite();
    graphics->append(&testSprite);
	gameInstance = this;
}


void Game::update()
{
    mPulse += .01f;
    if (mPulse > 1)
    {
        mPulse = 0;
    }
}


void Game::draw(Graphics* graphics)
{
    if (!graphics->isInitialized())
    {
        Log("WARNING", "GraphicsContext not initialized", "");
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(Input::getX() / graphics->getScreenWidth(), mPulse,
        (Input::getY()) / graphics->getScreenHeight(), 1);

    graphics->draw();
}


void readFiles(FileManager& fileManager)
{
    Log("-----", "----- -----", "");
    Log("fm", "Begin", "");
    {
        char buffer[1024];
        getcwd(buffer, sizeof(buffer));
        Log("fm", "path = '%s'", buffer);
        const std::string file = "test.txt";

        std::string str;

        str = "Hello World!";
        Log("fm", "Writing...", "");
        Log("fm", "success? %s", fileManager.writeFile(FileManager::Internal, file, str) ? "true" : "false");
        Log("fm", "line = '%s'", str.c_str());

        str = "";
        Log("fm", "Reading...", "");
        Log("fm", "success? %s", fileManager.readFile(FileManager::Internal, file, str) ? "true" : "false");
        Log("fm", "line = '%s'", str.c_str());
    }
    Log("fm", "End", "");
    Log("-----", "----- -----", "");
}


bool Game::isRunning()
{
    return mIsRunning;
}


void Game::stop()
{
    mIsRunning = false;
}

void Game::start()
{
    mIsRunning = true;
}

