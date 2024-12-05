#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "LinkListLib/LinkedList.h"
#include "Food/Food.h"
#include "Level/LevelConfig.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class InputState
	{
		PROCESSING,
		WAITING
	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N
	};

	enum class LinkListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	class  SnakeController
	{
	public:


		 SnakeController();
		~ SnakeController();

		void initialize();
		void update();
		void render();


		void spwanSnake();
		void respwanSnake();
		SnakeState getSnakeState();
		void setSnakeState(SnakeState state);

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		void setPlayerScore(int score);

		TimeComplexity getTimeComplexity();
		LinkListOperations getLinkListOperations();

		void createLinkList(Level::LinkListType link_list_type);


	private:
		const float movement_frame_duration = 0.1f;
		float elscaped_time;
		const int snake_length = 10.0;
		const float restart_duration = 2.f;
		float restart_timer;
		const sf::Vector2i snake_default_position = sf::Vector2i(25, 10);
		Direction default_snake_direction = Direction::RIGHT;
		SnakeState current_snakestate;
		Direction current_snake_direction;
		void processPlayerInput();
		void updateSnakedirection();
		void moveSnake();
		void processCollosionDetection();
		void handleRestart();
		void reset();
		void delayUpdate();
		InputState input_state;

		void bodyCollision();
		void elementCollision();
		void foodCollision();
		void onFoodCollected(Food::FoodType food_type);
		void destroyFood();

		int player_score;
		TimeComplexity time_complexity;
		LinkListOperations link_list_operation;
		LinkListLib::LinkList* linked_list;

		void initializeLinkList();

	};


}