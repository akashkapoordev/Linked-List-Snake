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

	std::vector<sf::Vector2i> PlayerService::getCurrentSnakePositionList()
	{
		return snake_controller->getCurrentSnakePositionList();
	}

	int PlayerService::getPlayerScore()
	{
		return snake_controller->getPlayerScore();
	}

	TimeComplexity PlayerService::getTimeComplexity()
	{
		return snake_controller->getTimeComplexity();
	}

	LinkListOperations PlayerService::getLinkListOperation()
	{
		return snake_controller->getLinkListOperations();
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

}
