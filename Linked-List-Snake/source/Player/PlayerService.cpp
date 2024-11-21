#include "Player/PlayerService.h"


namespace Player
{
	PlayerService::PlayerService()
	{
		createController();
	}
	PlayerService::~PlayerService()
	{
		delete(snake_controller);
	}

	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}

	void PlayerService::update()
	{
		snake_controller->update();
	}

	void PlayerService::render()
	{
		snake_controller->render();
	}

	void PlayerService::spwanPlayer()
	{
		snake_controller->spwanSnake();
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

}
