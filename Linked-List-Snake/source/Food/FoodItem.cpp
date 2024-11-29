#include "Food/FoodItem.h"
#include "Global/Config.h"
#include "Level/LevelView.h"
#include <iostream>
#include <string>
using namespace std;
namespace Food
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;

	FoodItem::FoodItem()
	{
		createImageService();
	}
	FoodItem::~FoodItem()
	{
		destroy();
	}
	void FoodItem::initialize(sf::Vector2i position, float width, float height, FoodType type)
	{
		grid_position = position;
		food_width = width;
		food_height = height;
		food_type = type;

		initializeFoodImage();
	}
	void FoodItem::update()
	{
		food_image->update();
	}
	void FoodItem::render()
	{
		food_image->render();
	}
	FoodType FoodItem::getFoodType()
	{
		return food_type;
	}
	sf::String FoodItem::getFoodTextures()
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			return Config::apple_texture_path;
		case Food::FoodType::MANGO:
			return Config::mango_texture_path;
		case Food::FoodType::ORANGE:
			return Config::orange_texture_path;
		case Food::FoodType::PIZZA:
			return Config::pizza_texture_path;
		case Food::FoodType::BURGER:
			return Config::burger_texture_path;
		case Food::FoodType::CHEESE:
			return Config::cheese_texture_path;
		case Food::FoodType::POISION:
			return Config::poision_texture_path;
		case Food::FoodType::ALCOHOL:
			return Config::alcohol_texture_path;
		}
	}
	void FoodItem::createImageService()
	{
		food_image = new ImageView();
	}
	void FoodItem::initializeFoodImage()
	{
		sf::Vector2f position = getfoodPosition();
		sf::String food_texture = getFoodTextures();

	
        // Replace the problematic line with the following
        std::cout << food_texture.toAnsiString() << std::endl;
		food_image->initialize(food_texture, food_width, food_height, position);
		food_image->show();

	}
	void FoodItem::destroy()
	{
		delete(food_image);
	}
	sf::Vector2f FoodItem::getfoodPosition()
	{
		float x = LevelView::border_offset_left + (food_width + grid_position.x);
		float y = LevelView::border_offset_top + (food_height + grid_position.y);
		return sf::Vector2f(x, y);
	}
}