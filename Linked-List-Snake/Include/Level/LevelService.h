#pragma once
#include "LevelConfig.h"
namespace Level
{
	class LevelController;
	class LevelService
	{
	public:
		LevelService();
		~LevelService();
		void initialize();
		void update();
		void render();

		void createLevel(LinkListType level_type);
		float cellWidth();
		float cellHeigth();
		LevelNumber getCurrentLevel();
		void setLevelNumber(LevelNumber number);

	private:
		LevelController* levelController;
		LevelNumber current_level;
		void spwanLevelElements(LevelNumber level_number);
		void spwanFood();
	};
}