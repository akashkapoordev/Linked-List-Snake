#pragma once
#include "LevelNumber.h"
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

		void createLevel(LevelNumber number);
		float cellWidth();
		float cellHeigth();
		LevelNumber getCurrentLevel();

	private:
		LevelController* levelController;
		LevelNumber current_level;
		void spwanLevelElements(LevelNumber level_number);
		void spwanFood();
	};
}