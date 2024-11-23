#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include <iostream>

namespace Player
{
	using namespace Global;
	using namespace LinkList;

	SnakeController::SnakeController()
	{
		single_link_list = nullptr;
		createSingleLinkList();
	}
	SnakeController::~SnakeController()
	{
		delete(single_link_list);
	}
	void SnakeController::initialize()
	{
		float cell_width = ServiceLocator::getInstance()->getLevelService()->cellWidth();
		float cell_height = ServiceLocator::getInstance()->getLevelService()->cellHeigth();

		single_link_list->initialize(cell_width, cell_height, snake_default_position, default_snake_direction);
		//std::cout << cell_width << std::endl;
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
		single_link_list->render();
	}
	void SnakeController::spwanSnake()
	{
		for (int i = 0; i < snake_length; i++)
		{
			single_link_list->attachNewTail();
		}
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
	void SnakeController::createSingleLinkList()
	{
		single_link_list = new SingleLinkedList();
	}
}

