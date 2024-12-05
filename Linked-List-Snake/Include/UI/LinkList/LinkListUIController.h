#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"
namespace UI
{
	namespace LinkListUI
	{
		class ListLinkUIController:public Interface::IUIController
		{
		public:
			ListLinkUIController();
			~ListLinkUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float single_list_button_y_position = 500.f;
			const float double_list_button_y_position = 700.f;
			const float main_menu_button_y_position = 900.f;

			const float background_alpha = 85.f;


			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* single_link_list_button;
			UI::UIElement::ButtonView* double_link_list_button;
			UI::UIElement::ButtonView* main_menu_button;


			void createBackgroundImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void destroy();

		};

	}
}