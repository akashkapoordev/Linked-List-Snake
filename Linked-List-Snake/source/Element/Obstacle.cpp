#include "Element/Obstacle.h"
#include "Global/ServiceLocator.h";
#include "Global/Config.h";
#include "Level/LevelView.h"

namespace Element
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;
	Obstacle::Obstacle()
	{
		createImage();
	}

	Obstacle::~Obstacle()
	{
		delete(obstacle_image);
	}

	void Obstacle::intialize(sf::Vector2i pos, float width, float height)
	{
		grid_position = pos;
		obstacle_width = width;
		obstacle_height = height;
	}

	void Obstacle::update()
	{
		obstacle_image->update();
	}

	void Obstacle::render()
	{
		obstacle_image->render();
	}

	void Obstacle::createImage()
	{
		obstacle_image = new ImageView();
	}

	void Obstacle::initializeObstacleImage()
	{
		sf::Vector2f screen_position = getObstacleImagePosition();
		obstacle_image->initialize(Config::obstacle_texture_path, obstacle_width, obstacle_height, screen_position);
	}

	sf::Vector2f Obstacle::getObstacleImagePosition()
	{
		float x = LevelView::border_offset_left + (obstacle_width * grid_position.x);
		float y = LevelView::LevelView::border_offset_top + (obstacle_height * grid_position.y);
		return sf::Vector2f(x, y);
	}

}
