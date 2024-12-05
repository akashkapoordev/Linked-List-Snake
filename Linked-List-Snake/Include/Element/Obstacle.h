#pragma once
#include "UI/UIElement/ImageView.h"
namespace Element
{
	class Obstacle
	{
	public:
		Obstacle();
		~Obstacle();

		void intialize(sf::Vector2i pos, float width, float height);
		void update();
		void render();
		sf::Vector2i getObstaclePositionList();

	private:
		UI::UIElement::ImageView* obstacle_image;
		sf::Vector2i grid_position;
		float obstacle_width;
		float obstacle_height;
		void createImage();
		void initializeObstacleImage();
		sf::Vector2f getObstacleImagePosition();

	};

}