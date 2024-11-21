#pragma once
#include <vector>
#include "Level/LevelData.h" 

namespace Level
{
	class LevelModel
	{
	public:
		static const int number_of_rows = 28;
		static const int number_of_columns = 50;

		LevelModel();
		~LevelModel();

		void initialize(float width, float height);
		float getWidth();
		float getHeight();

	private:
		std::vector<LevelData> level_configuration; 
		float cell_height;
		float cell_width;
	};
}