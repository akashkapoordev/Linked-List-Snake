#pragma once
#include "UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class RectangleShapeView : public UIView
		{
		public:
			sf::RectangleShape rectangle_shape;

			RectangleShapeView();
			virtual ~RectangleShapeView();

			virtual void initialize(sf::Vector2f rectangle_size, sf::Vector2f rectangle_position, int outline_thickness, sf::Color fill_color, sf::Color outline_color);
			virtual void update() override;
			virtual void render() override;


			virtual void setRectangleSize(sf::Vector2f rectangle_size);
			virtual void setRectanglePosition(sf::Vector2f rectangle_position);
			virtual void setOutlineThickness(int outline_thickness);
			virtual void setFillColor(sf::Color fill_color);
			virtual void setOutlineColor(sf::Color outline_color);
			virtual void show() override;



		private:
		};
	}
}