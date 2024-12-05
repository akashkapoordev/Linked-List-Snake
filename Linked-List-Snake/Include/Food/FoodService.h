#pragma once
#include "Food/FoodItem.h"
#include "LinkListLib/Node.h"
#include <random>
namespace Food
{
	enum class FoodSpwaningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};
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
		void reset();

		bool processFoodCollision(LinkListLib::Node* head_node, FoodType& out_foodtype);
		void destroyFood();

	private:
		const float spwan_timer = 4.0f;
		float elapsed_timer;
		FoodItem* current_food;
		float food_width;
		float food_height;
		FoodItem* createFoodItem(sf::Vector2i position, FoodType type);
		sf::Vector2i getRandomPosition();
		bool isVaildPosition(std::vector<sf::Vector2i> pos_data,sf::Vector2i food_position);

		FoodType getRandomFoodType();

		void updateElapsedDuration();
		void handleFoodSpwaning();
		void stopFoodSpwaning();
		FoodSpwaningStatus current_spwaning_status;
	};


}