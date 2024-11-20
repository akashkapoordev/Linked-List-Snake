#include "Level/LevelService.h"


namespace Level
{
	LevelService::LevelService()
	{
		levelController = new LevelController();
	}

	LevelService::~LevelService()
	{
		delete(levelController);
	}

	void Level::LevelService::initialize()
	{
		levelController->initialize();
	}

	void Level::LevelService::update()
	{
		levelController->update();
	}

	void Level::LevelService::render()
	{
		levelController->render();
	}
}
