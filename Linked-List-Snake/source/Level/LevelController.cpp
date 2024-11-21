#include "Level/LevelController.h"
#include "Level/LevelModel.h"
#include "Level/LevelView.h"

namespace Level
{
	Level::LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView();
	}

	Level::LevelController::~LevelController()
	{
		delete(level_model);
		delete(level_view);
	}

	void Level::LevelController::initialize()
	{
		level_model->initialize(level_view->getWidth(), level_model->getHeight());
		level_view->initialize();
	}

	void Level::LevelController::update()
	{
		level_view->update();
	}

	void Level::LevelController::render()
	{
		level_view->render();
	}
	void LevelController::createLevel(LevelNumber level_number)
	{
		current_level = level_number;
	}
	float LevelController::cellHeight()
	{
		return level_model->getHeight();
	}
	float LevelController::cellWidth()
	{
		return level_model->getWidth();
	}
}


