#include "Player/SnakeController.h"

namespace Player
{
	SnakeController::SnakeController()
	{
	}
	SnakeController::~SnakeController()
	{
	}
	void SnakeController::initialize()
	{
	}
	void SnakeController::update()
	{
		switch (getSnakeState())
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			moveSnake();
			processCollosionDetection();
			break;
		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}
	void SnakeController::render()
	{
	}
	void SnakeController::spwanSnake()
	{
	}
	void SnakeController::respwanSnake()
	{
	}
	SnakeState SnakeController::getSnakeState()
	{
		return current_snakestate;
	}
	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snakestate = state;
	}
	void SnakeController::processPlayerInput()
	{
	}
	void SnakeController::updateSnakedirection()
	{
	}
	void SnakeController::moveSnake()
	{
	}
	void SnakeController::processCollosionDetection()
	{
	}
	void SnakeController::handleRestart()
	{
	}
	void SnakeController::reset()
	{
	}
}

