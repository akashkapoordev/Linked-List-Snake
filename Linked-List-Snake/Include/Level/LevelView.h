#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"
namespace Level
{
	class LevelView
	{
	public:
		const sf::Color backgroundColor = sf::Color(180, 200, 160);
		const sf::Color boarderColor = sf::Color::Black;


		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;

		LevelView();
		~LevelView();
		void initialize();
		void update();
		void render();

		float getWidth();
		float getHeight();

		void calculateGridExtends();

	private:
		float grid_size_height;
		float grid_size_width;
		UI::UIElement::RectangleShapeView* background;
		UI::UIElement::RectangleShapeView* border_rectangle;
		void createBorder();
		void createBackground();
		void initializeBackground();
		void initializeBorder();

	};

}