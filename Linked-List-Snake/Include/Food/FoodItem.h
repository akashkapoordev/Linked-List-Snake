#pragma once
#include "UI/UIElement/ImageView.h"
#include "Food.h"
namespace Food
{
	class FoodItem
	{
	public:
		static const int number_of_food = 8;
		FoodItem();
		~FoodItem();

		void initialize(sf::Vector2i position, float width, float height, FoodType type);
		void update();
		void render();

		FoodType getFoodType();
		sf::Vector2i getFoodGridPosition();
	private:
		UI::UIElement::ImageView* food_image;
		sf::Vector2i grid_position;
		float food_width;
		float food_height;
		FoodType food_type;
		sf::String getFoodTextures();

		void createImageService();
		void initializeFoodImage();
		void destroy();

		sf::Vector2f getfoodPosition();

	};


}