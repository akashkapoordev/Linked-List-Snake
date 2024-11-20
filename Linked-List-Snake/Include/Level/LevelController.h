#pragma once
namespace Level
{
	enum class LevelNumber;
	class LevelController
	{
	public:
		LevelController();
		~LevelController();
		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_number);
	private:
		LevelNumber current_level;
	};

}