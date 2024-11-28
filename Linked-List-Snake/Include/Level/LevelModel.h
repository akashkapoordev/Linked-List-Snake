#pragma once
#include <SFML/System/Vector2.hpp>
#include "Element/ElementService.h"
#include "Element/ElementData.h"
#include "Level/LevelData.h"
#include <vector>

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

		const std::vector<Element::ElementData>& getElementDataList(int level_to_load);

	private:
		std::vector<Element::ElementData> level_one_element_list = {};
		//std::vector<Element::ElementData> level_two_element_list;
		std::vector<LevelData> level_configuration; 
		float cell_height;
		float cell_width;

		void initializeLevelData();
	};
}