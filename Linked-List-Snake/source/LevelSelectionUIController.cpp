#include "../header/LevelSelectionUIController.h"
#include "../header/GameService.h"
#include "../header/GraphicService.h"
#include "../header/SoundService.h"
#include "../header/EventService.h"
#include "../header/ButtonView.h"
#include "../header/Config.h"
#include "../header/LevelService.h"

LevelSelectionUIController::LevelSelectionUIController()
{
    createButtons();
}

LevelSelectionUIController::~LevelSelectionUIController()
{
    destroy();
}

void LevelSelectionUIController::initialize()
{
    initializeButtons();
    registerButtonCallback();
}

void LevelSelectionUIController::createButtons()
{
    level_one_button = new ButtonView();
    level_two_button = new ButtonView();
    menu_button = new ButtonView();
}

void LevelSelectionUIController::initializeButtons()
{
    float x_position = calculateLeftOffsetForButton();

    level_one_button->initialize("Level One Button", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_one_button_y_position));
    level_two_button->initialize("Level Two Button", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(x_position, level_two_button_y_position));
    menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_position, menu_button_y_position));
}

void LevelSelectionUIController::registerButtonCallback()
{
    level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOneButtonCallback, this));
    level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwoButtonCallback, this));
    menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
}

float LevelSelectionUIController::calculateLeftOffsetForButton()
{
    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
}

void LevelSelectionUIController::levelOneButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
    GameService::setGameState(GameState::GAMEPLAY);
    ServiceLocator::getInstance()->getLevelService()->createLevel(Level::ONE);
}

void LevelSelectionUIController::levelTwoButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
    GameService::setGameState(GameState::GAMEPLAY);
    ServiceLocator::getInstance()->getLevelService()->createLevel(Level::TWO);
}

void LevelSelectionUIController::menuButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
    GameService::setGameState(GameState::MAIN_MENU);
}

void LevelSelectionUIController::update()
{
    level_one_button->update();
    level_two_button->update();
    menu_button->update();
}

void LevelSelectionUIController::render()
{
    ServiceLocator::getInstance()->getGraphicService()->drawBackground();
    level_one_button->render();
    level_two_button->render();
    menu_button->render();
}

void LevelSelectionUIController::show()
{
    level_one_button->show();
    level_two_button->show();
    menu_button->show();
}

void LevelSelectionUIController::destroy()
{
    delete (level_one_button);
    delete (level_two_button);
    delete (menu_button);
}