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

	enum class InputState
	{
		PROCESSING,
		WAITING
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
		const float movement_frame_duration = 0.1f;
		float elscaped_time;
		const int snake_length = 10.0;
		const float restart_duration = 2.f;
		float restart_timer;
		const sf::Vector2i snake_default_position = sf::Vector2i(25, 15);
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
		LinkList::SingleLinkedList* single_link_list;
		void createSingleLinkList();
		InputState input_state;
		

	};


}