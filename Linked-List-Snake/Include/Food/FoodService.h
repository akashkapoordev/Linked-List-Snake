#pragma once
#include "Food/FoodItem.h"
#include <random>
namespace Food
{
	class FoodService
	{
	public:
		FoodService();
		~FoodService();

		std::default_random_engine random_engine;
		std::random_device rd;

		void initialize();
		void update();
		void render();
		void spwanFood();
		void startFoodSpawing();
		sf::Vector2i getVaildSpawnPosition();

	private:
		FoodItem* current_food;
		float food_width;
		float food_height;

		FoodItem* createFoodItem(sf::Vector2i position, FoodType type);
		sf::Vector2i setRandomPosition();
		bool isVaildPosition(std::vector<sf::Vector2i> pos_data,sf::Vector2i food_position);

		FoodType getRandomFoodType();
	};


}