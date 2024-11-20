#include "Level/LevelView.h"
#include "Global/ServiceLocator.h"

namespace Level
{
	using namespace UI::UIElement;
	using namespace Global;

	LevelView::LevelView()
	{
		createBackground();
		createBorder();

		
	}

	LevelView::~LevelView()
	{
		delete(background);
		delete(border_rectangle);
	}

	void Level::LevelView::initialize()
	{
		calculateGridExtends();
		initializeBackground();
		initializeBorder();
	}

	void Level::LevelView::update()
	{
		background->update();
		border_rectangle->update();
	}

	void Level::LevelView::render()
	{
		background->render();
		border_rectangle->render();
	}

	float LevelView::getWidth()
	{
		return grid_width;
	}

	float LevelView::getHeight()
	{
		return grid_height;
	}

	void LevelView::calculateGridExtends()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		grid_width = game_window->getSize().x - 2 * border_offset_left;
		grid_height = game_window->getSize().y - 2 * border_offset_top;
	}

	void LevelView::createBorder()
	{
		border_rectangle = new RectangleShapeView();
	}

	void LevelView::createBackground()
	{
		background = new RectangleShapeView();
	}

	void LevelView::initializeBackground()
	{
		sf::RenderWindow* window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		background->initialize(sf::Vector2f(window->getSize().x, window->getSize().y), sf::Vector2f(0, 0), 0, backgroundColor, sf::Color::Transparent);
		background->show();
	}

	void LevelView::initializeBorder()
	{
		sf::Vector2f rectangle_size = sf::Vector2f(grid_width, grid_height);
		border_rectangle->initialize(rectangle_size, sf::Vector2f(border_offset_left, border_offset_top), border_thickness, sf::Color::Transparent, boarderColor);
		border_rectangle->show();
	}

}

