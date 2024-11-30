#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Event/EventService.h"
#include <iostream>
#include "Sound/SoundService.h"
#include "Food/FoodService.h"

namespace Player
{
	using namespace Global;
	using namespace LinkList;
	using namespace Event;
	using namespace Sound;
	using namespace Food;

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
		single_link_list->removeAllNodes();
		reset();
		spwanSnake();
	}
	SnakeState SnakeController::getSnakeState()
	{
		return current_snakestate;
	}
	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snakestate = state;
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return single_link_list->getNodePositionList();
	}

	void SnakeController::processPlayerInput()
	{
		if (input_state == InputState::PROCESSING)
		{
			return;
		}
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey()&& current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			input_state = InputState::PROCESSING;
		}

		

	}
	void SnakeController::updateSnakedirection()
	{
		single_link_list->updateNodeDirection(current_snake_direction);
	}
	void SnakeController::moveSnake()
	{
		single_link_list->updateNodePosition();
	}
	void SnakeController::processCollosionDetection()
	{
		bodyCollision();
		elementCollision();
		foodCollision();
	}
	void SnakeController::handleRestart()
	{
		restart_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_timer >= restart_duration)
		{
			respwanSnake();
		}
	}
	void SnakeController::reset()
	{
		current_snakestate = SnakeState::ALIVE;
		current_snake_direction = default_snake_direction;
		elscaped_time = 0;
		restart_timer = 0;
		input_state = InputState::WAITING;
		
	}
	void SnakeController::delayUpdate()
	{
		elscaped_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (elscaped_time >= movement_frame_duration)
		{
			elscaped_time = 0;
			updateSnakedirection();
			processCollosionDetection();

			if (getSnakeState() == SnakeState::ALIVE)
			{
				moveSnake();
				input_state = InputState::WAITING;
			}
		}
	}
	void SnakeController::createSingleLinkList()
	{
		single_link_list = new SingleLinkedList();
	}
	void SnakeController::bodyCollision()
	{
		if (single_link_list->processNodeCollision())
		{

			setSnakeState(SnakeState::DEAD);
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
		}
	}
	void SnakeController::elementCollision()
	{
		Element::ElementService* element_service = ServiceLocator::getInstance()->getElementService();
		if (element_service->processElementCollision(single_link_list->getHeadNode()))
		{
			setSnakeState(SnakeState::DEAD);
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
		}
		
	}
	void SnakeController::foodCollision()
	{
		Food::FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(single_link_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);
			onFoodCollected(food_type);

		}
	}

	void SnakeController::onFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			break;
		case Food::FoodType::MANGO:
			break;
		case Food::FoodType::ORANGE:
			break;
		case Food::FoodType::PIZZA:
			break;
		case Food::FoodType::BURGER:
			break;
		case Food::FoodType::CHEESE:
			break;
		case Food::FoodType::POISION:
			break;
		case Food::FoodType::ALCOHOL:
			break;
		default:
			break;
		}
	}

}

