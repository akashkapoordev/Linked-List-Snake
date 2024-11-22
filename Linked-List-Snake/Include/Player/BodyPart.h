#pragma once
#include "UI/UIElement/ImageView.h"
#include "Player/Direction.h"

namespace Player
{
	class BodyPart
	{
	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, Direction dir, sf::Vector2i pos);
		void update();
		void render();
		void setDirection(Direction dir);
	private:
		UI::UIElement::ImageView* body_part_image;
		Direction direction;
		sf::Vector2i grid_position;
		float body_part_width;
		float body_part_height;

		void createBodyPartImage();
		void initializeBodyImage();
		sf::Vector2f getBodyPartScreenPositon();
		float getRotationAngle();

	};

}