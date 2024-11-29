#pragma once
#include "Food/FoodItem.h"
namespace Food
{
	class FoodService
	{
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();
		void spwanFood();
		void startFoodSpawing();

	private:
		FoodItem* current_food;
		float food_width;
		float food_height;

		FoodItem* createFoodItem(sf::Vector2i position, FoodType type);
	};


}