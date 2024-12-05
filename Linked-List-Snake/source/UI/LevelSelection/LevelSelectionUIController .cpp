#include "UI/LevelSelection/LevelSelectionUIController .h"
#include "Global/ServiceLocator.h"
#include "Global/Config.h"
#include "Main/GameService.h"
#include "Level/LevelConfig.h"


namespace UI
{
	namespace LevelSelection
	{
		using namespace UIElement;
		using namespace Global;
		using namespace Main;
		using namespace Level;

		LevelSelectionUIController::LevelSelectionUIController()
		{
			createBackgroundImage();
			createButtons();
		}

		LevelSelectionUIController::~LevelSelectionUIController()
		{
		}
		void LevelSelectionUIController::initialize()
		{

			initializeBackgroundImage();
			initializeButtons();
			registerCallback();
		}
		void LevelSelectionUIController::update()
		{
			background_image->update();
			level_one->update();
			level_two->update();
			main_menu->update();
		}
		void LevelSelectionUIController::render()
		{
			background_image->render();
			level_one->render();
			level_two->render();
			main_menu->render();
		}
		void LevelSelectionUIController::createBackgroundImage()
		{
			background_image = new ImageView();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LevelSelectionUIController::createButtons()
		{
			level_one = new ButtonView();
			level_two = new ButtonView();
			main_menu = new ButtonView();
		}

		void LevelSelectionUIController::initializeButtons()
		{
			level_one->initialize("Level One", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0, levelone_button_y_position));
			level_two->initialize("Level Two", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(0, leveltwo_button_y_position));
			main_menu->initialize("MainMenu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, mainmenu_button_y_position));

			level_one->setCentreAlinged();
			level_two->setCentreAlinged();
			main_menu->setCentreAlinged();
		}

		void LevelSelectionUIController::registerCallback()
		{
			level_one->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOneButtonCallback, this));
			level_two->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwoButtonCallback, this));
			main_menu->registerCallbackFuntion(std::bind(&LevelSelectionUIController::mainmenuButtonCallback, this));
		}

		void LevelSelectionUIController::levelOneButtonCallback()
		{
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setLevelNumber(Level::LevelNumber::LEVEL_1);
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
		}

		void LevelSelectionUIController::levelTwoButtonCallback ()
		{
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->getLevelService()->setLevelNumber(Level::LevelNumber::LEVEL_2);
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);

		}

		void LevelSelectionUIController::mainmenuButtonCallback()
		{
			GameService::setGameState(GameState::MAIN_MENU);
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);

			
		}

		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_one->show();
			level_two->show();
			main_menu->show();
		}


	}
}

