#pragma once
#include "Level/LevelController.h"
namespace Level
{
	class LevelService
	{
	public:
		LevelService();
		~LevelService();
		void initialize();
		void update();
		void render();
	private:
		LevelController* levelController;
	};
}