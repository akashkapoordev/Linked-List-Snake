#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Event/EventService.h"
#include <iostream>

namespace Player
{
	using namespace Global;
	using namespace LinkList;
	using namespace Event;
	inline std::ostream& operator<<(std::ostream& os, const Direction& direction)
	{
		switch (direction)
		{
		case Direction::UP: os << "UP"; break;
		case Direction::DOWN: os << "DOWN"; break;
		case Direction::LEFT: os << "LEFT"; break;
		case Direction::RIGHT: os << "RIGHT"; break;
		}
		return os;
	}
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
			delayUpdate();
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
		for (int i = 0; i <= snake_length; i++)
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
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey()&& current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
		}

	}
	void SnakeController::updateSnakedirection()
	{
		
    

   
		single_link_list->updateNodeDirection(Direction::RIGHT);
	}
	void SnakeController::moveSnake()
	{
		single_link_list->updateNodePosition();
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
	void SnakeController::delayUpdate()
	{
		elscaped_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (elscaped_time >= movment_frame_diration)
		{
			elscaped_time = 0;
			updateSnakedirection();
			processCollosionDetection();
			moveSnake();
		}
	}
	void SnakeController::createSingleLinkList()
	{
		single_link_list = new SingleLinkedList();
	}
}

