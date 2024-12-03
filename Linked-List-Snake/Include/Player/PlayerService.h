#pragma once
#include "Player/SnakeController.h"
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

		void spwanPlayer();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkListOperations getLinkListOperation();

	private:
		SnakeController* snake_controller;
		void createController();
	};


}