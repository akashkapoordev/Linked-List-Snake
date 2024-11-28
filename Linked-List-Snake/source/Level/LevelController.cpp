#include "Level/LevelController.h"
#include "Level/LevelModel.h"
#include "Level/LevelView.h"

namespace Level
{
	using namespace Element;

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
		level_view->initialize();
		level_model->initialize(level_view->getWidth(), level_view->getHeight());

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

	const std::vector<Element::ElementData>& LevelController::getElementDataList(int level_to_load)
	{
		return level_model->getElementDataList(level_to_load);
	}

}


