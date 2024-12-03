#include "Level/LevelService.h"
#include "Level/LevelController.h"
#include "Global/ServiceLocator.h"
#include "Element/ElementService.h"
#include "Level/LevelModel.h"
#include "Food/FoodService.h"

namespace Level
{
	using namespace Global;
	using namespace Food;
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
		current_level = number;
		//levelController->createLevel(number);
		spwanLevelElements(number);
		spwanFood();
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

	LevelNumber LevelService::getCurrentLevel()
	{
		return current_level;
	}

	void LevelService::spwanLevelElements(LevelNumber level_number)
	{
		float cell_width = levelController->cellWidth();
		float cell_height = levelController->cellHeight();

		std::vector<Element::ElementData> element_data_list = levelController->getElementDataList((int)level_number);
		ServiceLocator::getInstance()->getElementService()->spwanElements(element_data_list, cell_width, cell_height);
	}

	void LevelService::spwanFood()
	{
		ServiceLocator::getInstance()->getFoodService()->startFoodSpawing();
	}
	
}
