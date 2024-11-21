#include "Level/LevelModel.h"


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


}


