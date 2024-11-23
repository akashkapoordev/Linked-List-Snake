#include "Level/LevelService.h"
#include "Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

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
	void LevelService::createLevel(LevelNumber number)
	{
		levelController->createLevel(number);
		ServiceLocator::getInstance()->getPlayerService()->spwanPlayer();
	}
	float LevelService::cellWidth()
	{
		return levelController->cellWidth();
	}
	float LevelService::cellHeigth()
	{
		return levelController->cellHeight();
	}
}
