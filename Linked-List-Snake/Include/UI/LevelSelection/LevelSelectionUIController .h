#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController:public Interface::IUIController
		{
		public:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float levelone_button_y_position = 500.f;
			const float leveltwo_button_y_position = 700.f;
			const float mainmenu_button_y_position = 900.f;

			const float background_alpha = 85.f;


			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;


		private:
			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* level_one;
			UI::UIElement::ButtonView* level_two;
			UI::UIElement::ButtonView* main_menu;

			void createBackgroundImage();
			void initializeBackgroundImage();
			
			void createButtons();
			void initializeButtons();

			void registerCallback();
			void levelOneButtonCallback();
			void levelTwoButtonCallback();
			void mainmenuButtonCallback();
		};
	}
}