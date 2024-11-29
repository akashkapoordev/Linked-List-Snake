#include "Food/FoodService.h"
#include "Level/LevelService.h"
#include "Global/ServiceLocator.h"
#include <iostream>
namespace Food
{
	using namespace Global;
	FoodService::FoodService()
	{
		current_food = nullptr;
	}
	FoodService::~FoodService()
	{
		delete(current_food);
	}
	void FoodService::initialize()
	{
		;
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
		current_food = createFoodItem(sf::Vector2i(4, 6), FoodType::BURGER);
	}
	void FoodService::startFoodSpawing()
	{
		food_width = ServiceLocator::getInstance()->getLevelService()->cellWidth();
		food_height = ServiceLocator::getInstance()->getLevelService()->cellHeigth();
		std::cout << food_width << std::endl;
		std::cout << food_height << std::endl;
		spwanFood();
	}
	FoodItem* FoodService::createFoodItem(sf::Vector2i position,FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, food_width, food_height, type);
		return food;
	}
}