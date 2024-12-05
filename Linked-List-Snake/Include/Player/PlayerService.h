#pragma once
#include "Player/SnakeController.h"
#include "Level/LevelConfig.h"
namespace Player
{
	class  PlayerService
	{
	public:
		 PlayerService();
		~ PlayerService();

		void initialize();
		void update();
		void render();

		void spwanPlayer(Level::LinkListType level_type);
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkListOperations getLinkListOperation();

	private:
		SnakeController* snake_controller;
		void createController();
	};


}