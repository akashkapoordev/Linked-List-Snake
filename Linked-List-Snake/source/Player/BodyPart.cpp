#include "Player/BodyPart.h"
#include "Global/ServiceLocator.h";
#include "Global/Config.h";

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}
	BodyPart::~BodyPart()
	{
		delete(body_part_image);
	}
	void BodyPart::initialize(float width, float height, Direction dir, sf::Vector2i pos)
	{
		body_part_width = width;
		body_part_height = height;
		direction = dir;
		grid_position = pos;
		initializeBodyImage();
	}
	void BodyPart::render()
	{
		body_part_image->render();
	}
	void BodyPart::createBodyPartImage()
	{
		body_part_image = new ImageView();
	}
	void BodyPart::initializeBodyImage()
	{
		body_part_image->initialize(Config::snake_body_texture_path, body_part_width, body_part_height, sf::Vector2f(0, 0));
		body_part_image->setOriginAtCentre();
	}
}

