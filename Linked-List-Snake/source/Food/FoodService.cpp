#include "Food/FoodService.h"
#include "Level/LevelService.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelModel.h"
#include <iostream>
namespace Food
{
#include <SFML/System/Vector2.hpp>

	// Add this function to print sf::Vector2i
	std::ostream& operator<<(std::ostream& os, const sf::Vector2i& vector) {
		os << "(" << vector.x << ", " << vector.y << ")";
		return os;
	}

	using namespace Level;
	// Existing code...
	using namespace Global;
	FoodService::FoodService():random_engine(rd())
	{
		current_food = nullptr;
	}
	FoodService::~FoodService()
	{
		destroyFood();
	}
	void FoodService::initialize()
	{
		elapsed_timer = spwan_timer;
	}
	void FoodService::update()
	{
		if (current_spwaning_status == FoodSpwaningStatus::ACTIVE)
		{
			updateElapsedDuration();
			handleFoodSpwaning();
			
		}
		if(current_food) current_food->update();
		
	}
	void FoodService::render()
	{
		if (current_food) current_food->render();
	}
	void FoodService::spwanFood()
	{
		current_food = createFoodItem(getVaildSpawnPosition(), getRandomFoodType());
	}
	void FoodService::startFoodSpawing()
	{
		current_spwaning_status = FoodSpwaningStatus::ACTIVE;
		food_width = ServiceLocator::getInstance()->getLevelService()->cellWidth();
		food_height = ServiceLocator::getInstance()->getLevelService()->cellHeigth();
		
	}
	sf::Vector2i FoodService::getVaildSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> elements_position_data = ServiceLocator::getInstance()->getElementService()->getElementPosition();
		sf::Vector2i spawn_position;

		do spawn_position = getRandomPosition();
		while (!isVaildPosition(player_position_data, spawn_position) || !isVaildPosition(elements_position_data, spawn_position));

		return spawn_position;
	

	}
	void FoodService::reset()
	{
		elapsed_timer = 0;
	}
	bool FoodService::processFoodCollision(LinkListLib::Node* head_node, FoodType& out_foodtype)
	{
		if (current_food && current_food->getFoodGridPosition() == head_node->body_part.getgridPosition() )
		{
			out_foodtype = current_food->getFoodType();
			return true;
		}
		return false;

	}
	FoodItem* FoodService::createFoodItem(sf::Vector2i position,FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, food_width, food_height, type);
		return food;
	}
	sf::Vector2i FoodService::getRandomPosition()
	{
		std::uniform_int_distribution<int> x_distribution(0, LevelModel::number_of_columns - 1);
		std::uniform_int_distribution<int> y_distribution(0, LevelModel::number_of_rows - 1);

		int x_position = x_distribution(random_engine);
		int y_position = y_distribution(random_engine);

		return sf::Vector2i(x_position, y_position);

	}
	bool FoodService::isVaildPosition(std::vector<sf::Vector2i> pos_data, sf::Vector2i food_position)
	{
		for (int i = 0; i < pos_data.size(); i++)
		{
			if (pos_data[i] == food_position)
			{
				return false;
			}

		}
		return true;
	}
	FoodType FoodService::getRandomFoodType()
	{
		std::uniform_int_distribution<int> random_food(0, FoodItem::number_of_food - 1);

		return static_cast<FoodType>(random_food(random_engine));
	}
	void FoodService::updateElapsedDuration()
	{
		elapsed_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	
	}
	void FoodService::handleFoodSpwaning()
	{
		if (ServiceLocator::getInstance()->getPlayerService()->isPlayerDead())
		{
			destroyFood();
			return;
		}

		if (elapsed_timer >= spwan_timer)
		{
			destroyFood();
			reset();
			spwanFood();

		}
	}
	void FoodService::stopFoodSpwaning()
	{
		current_spwaning_status = FoodSpwaningStatus::IN_ACTIVE;
		destroyFood();
		reset();
	}
	void FoodService::destroyFood()
	{
		if (current_food) delete(current_food);
		current_food = nullptr;
	}
}