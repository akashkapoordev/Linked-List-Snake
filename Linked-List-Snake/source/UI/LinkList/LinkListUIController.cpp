#include "UI/LinkList/LinkListUIController.h"
#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace UI
{
	namespace LinkListUI
	{
		using namespace UI::UIElement;
		using namespace Global;

		ListLinkUIController::ListLinkUIController()
		{
			createBackgroundImage();
			createButtons();
		}
		ListLinkUIController::~ListLinkUIController()
		{
			destroy();
		}
		void ListLinkUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
		}
		void ListLinkUIController::update()
		{
			background_image->update();
			single_link_list_button->update();
			double_link_list_button->update();
			main_menu_button->update();
		}
		void ListLinkUIController::render()
		{
			background_image->render();
			single_link_list_button->render();
			double_link_list_button->render();
			main_menu_button->render();
		}
		void ListLinkUIController::show()
		{
			background_image->show();
			single_link_list_button->show();
			double_link_list_button->show();
			main_menu_button->show();
		}
		void ListLinkUIController::createBackgroundImage()
		{
			background_image = new ImageView();
		}
		void ListLinkUIController::createButtons()
		{
			single_link_list_button = new ButtonView();
			double_link_list_button = new ButtonView();
			main_menu_button = new ButtonView();
		}
		void ListLinkUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}
		void ListLinkUIController::initializeButtons()
		{
			single_link_list_button->initialize("Single Linked List", Config::single_linked_list_button_texture_path,button_width,button_height,sf::Vector2f(0,single_list_button_y_position));
			double_link_list_button->initialize("Double Linked List", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(0, double_list_button_y_position));
			main_menu_button->initialize("MainMenu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, main_menu_button_y_position));

			single_link_list_button->setCentreAlinged();
			double_link_list_button->setCentreAlinged();
			main_menu_button->setCentreAlinged();
		}
		void ListLinkUIController::destroy()
		{
			delete(background_image);
			delete(single_link_list_button);
			delete(double_link_list_button);
			delete(main_menu_button);
		}
	}
}
