#pragma once
namespace Level
{
	enum class LevelNumber;
	class LevelModel;
	class LevelView;
	class LevelController
	{
	public:
		LevelController();
		~LevelController();
		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_number);
		float cellHeight();
		float cellWidth();

		const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
	private:
		LevelNumber current_level;
		LevelModel* level_model;
		LevelView* level_view;
	};

}