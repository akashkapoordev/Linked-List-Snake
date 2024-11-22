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

	private:
		UI::UIElement::ImageView* body_part_image;
		Direction direction;
		sf::Vector2i grid_position;
		float body_part_width;
		float body_part_height;
	};

}