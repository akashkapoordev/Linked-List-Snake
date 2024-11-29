#include "Food/FoodService.h"
#include "Level/LevelService.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelModel.h"
#include <iostream>
namespace Food
{
	using namespace Global;
	FoodService::FoodService():random_engine(rd())
	{
		current_food = nullptr;
	}
	FoodService::~FoodService()
	{
		delete(current_food);
	}
	void FoodService::initialize()
	{
		
	}
	void FoodService::update()
	{
		current_food->update();
	}
	void FoodService::render()
	{
		current_food->render();
	}
	void FoodService::spwanFood()
	{
		current_food = createFoodItem(getVaildSpawnPosition(), getRandomFoodType());
	}
	void FoodService::startFoodSpawing()
	{
		food_width = ServiceLocator::getInstance()->getLevelService()->cellWidth();
		food_height = ServiceLocator::getInstance()->getLevelService()->cellHeigth();
		std::cout << food_width << std::endl;
		std::cout << food_height << std::endl;
		spwanFood();
	}
	sf::Vector2i FoodService::getVaildSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> element_position_data = ServiceLocator::getInstance()->getElementService()->getElementPosition();

		sf::Vector2i spwan_position;

		do spwan_position = setRandomPosition();
		while (!isVaildPosition(player_position_data, spwan_position) || !isVaildPosition(element_position_data, spwan_position));

		return spwan_position;
	

	}
	FoodItem* FoodService::createFoodItem(sf::Vector2i position,FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, food_width, food_height, type);
		return food;
	}
	sf::Vector2i FoodService::setRandomPosition()
	{
		std::uniform_int_distribution<int>x_distrbution(0, Level::LevelModel::number_of_columns-1);
		std::uniform_int_distribution<int>y_distribution(0, Level::LevelModel::number_of_rows - 1);

		int x_position = x_distrbution(random_engine);
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
}