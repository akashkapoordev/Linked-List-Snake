#include "Player/BodyPart.h"
#include "Global/ServiceLocator.h";
#include "Global/Config.h";
#include "Level/LevelView.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "Level/LevelModel.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Level;



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


    void BodyPart::update()
    {
        grid_position = getNextPosition();
        body_part_image->setPosition(getBodyPartScreenPositon());
        body_part_image->setRotation(getRotationAngle());
        body_part_image->update();
    }
	void BodyPart::render()
	{
		body_part_image->render();
	}
	void BodyPart::setDirection(Direction dir)
	{
		direction = dir;
	}
	void BodyPart::createBodyPartImage()
	{
		body_part_image = new ImageView();
	}
	void BodyPart::initializeBodyImage()
	{
		body_part_image->initialize(Config::snake_body_texture_path, body_part_width, body_part_height, getBodyPartScreenPositon());
		body_part_image->setOriginAtCentre();
	}
	sf::Vector2f BodyPart::getBodyPartScreenPositon()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * body_part_width) + (body_part_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * body_part_height) + (body_part_height / 2);
		return sf::Vector2f(x_screen_position, y_screen_position);
	}
	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Player::Direction::UP:
			return 270.0;
		case Player::Direction::DOWN:
			return 90.0;
		case Player::Direction::LEFT:
			return 180.0;
		case Player::Direction::RIGHT:
			return 0;
		}
	}
    sf::Vector2i BodyPart::getNextPositionUp()
    {
        int new_y = (grid_position.y - 1 + Level::LevelModel::number_of_rows) % Level::LevelModel::number_of_rows;
        return sf::Vector2i(grid_position.x, new_y);
    }
    sf::Vector2i BodyPart::getNextPositionDown()
    {
        return sf::Vector2i(grid_position.x, (grid_position.y + 1) % Level::LevelModel::number_of_rows);
    }
    sf::Vector2i BodyPart::getNextPositionLeft()
    {
        int new_x = (grid_position.x - 1 + LevelModel::number_of_columns) % LevelModel::number_of_columns;
        return sf::Vector2i(new_x, grid_position.y);
    }
    sf::Vector2i BodyPart::getNextPositionRight()
    {
		//std::cout << grid_position.x + 1 << std::endl;
        return sf::Vector2i((grid_position.x + 1) % Level::LevelModel::number_of_columns, grid_position.y);
    }
    sf::Vector2i BodyPart::getNextPosition()
    {
		switch (direction)
		{
		case Player::Direction::UP:
			return getNextPositionUp();
		case Player::Direction::DOWN:
			return getNextPositionDown();
		case Player::Direction::LEFT:
			return getNextPositionLeft();
		case Player::Direction::RIGHT:
			//std::cout << "Right" << std::endl;
			return getNextPositionRight();
		default:
			return grid_position;
		}
    }

	void BodyPart::setPosition(sf::Vector2i pos)
	{
		grid_position = pos;
	}
	Direction BodyPart::getDirection()
	{
		return direction;
	}
	sf::Vector2i BodyPart::getgridPosition()
	{
		return grid_position;
	}
}

