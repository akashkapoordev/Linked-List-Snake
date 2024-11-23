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

	private:
		SnakeController* snake_controller;
		void createController();
	};


}