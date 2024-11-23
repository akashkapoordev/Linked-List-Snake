#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "LinkList/SingleLinkedList.h"
namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
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

	private:
		const int snake_length = 10.0;
		const sf::Vector2i snake_default_position = sf::Vector2i(25, 25);
		Direction default_snake_direction = Direction::RIGHT;
		SnakeState current_snakestate;
		Direction current_snake_direction;
		void processPlayerInput();
		void updateSnakedirection();
		void moveSnake();
		void processCollosionDetection();
		void handleRestart();
		void reset();

		LinkList::SingleLinkedList* single_link_list;
		void createSingleLinkList();

	};


}