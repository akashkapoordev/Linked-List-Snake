#include "Level/LevelModel.h"
#include "Level/LevelNumber.h"

namespace Level
{
	LevelModel::LevelModel()
	{
	}

	LevelModel::~LevelModel()
	{
	}

	void LevelModel::initialize(float width, float height)
	{
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;
	}

	float LevelModel::getWidth()
	{
		return cell_width;
	}

	float LevelModel::getHeight()
	{
		return cell_height;
	}

	const std::vector<ElementData>& LevelModel::getElementDataList(int level_to_load)
	{
		// TODO: insert return statement here
		return*level_configuration[level_to_load].element_data_list;
	}

	void LevelModel::initializeLevelData()
	{
		level_configuration.push_back(LevelData(LevelNumber::LEVEL_1, &level_one_element_list));
		level_configuration.push_back(LevelData(LevelNumber::LEVEL_2, &level_two_element_list));
	}
}
