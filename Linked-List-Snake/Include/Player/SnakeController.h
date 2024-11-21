#pragma once
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
		SnakeState current_snakestate;
		void processPlayerInput();
		void updateSnakedirection();
		void moveSnake();
		void processCollosionDetection();
		void handleRestart();
		void reset();

	};


}