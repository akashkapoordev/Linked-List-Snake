#pragma once
#include "Element/ElementData.h"
namespace Level
{
	using namespace Element;
	struct LevelData
	{
	public:
		LevelData(LevelNumber index, std::vector<ElementData>* data_list) {
			level_index = index;
			element_data_list = data_list;
		};

		LevelNumber level_index;
		std::vector<ElementData>*element_data_list;
	};

}