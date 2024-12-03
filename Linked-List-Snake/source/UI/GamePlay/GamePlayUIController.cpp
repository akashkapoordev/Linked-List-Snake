#include "UI/GamePlay/GamePlayUIController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelModel.h"
#include "Player/SnakeController.h"

namespace UI
{
	namespace GamePlay
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Level;
		using namespace Player;

		GamePlayUIController::GamePlayUIController()
		{
			createText();
		}
		GamePlayUIController::~GamePlayUIController()
		{
			destroy();
		}
		void GamePlayUIController::initialize()
		{
			initializeTexts();
		}
		void GamePlayUIController::update()
		{
			updateLevelNumberText();
			updateScoreText();
			updateTimeComplexityText();
			updateOperationText();
		}
		void GamePlayUIController::render()
		{
			level_number_text->render();
			score_text->render();
			time_complexity_text->render();
			operation_text->render();
		}
		void GamePlayUIController::show()
		{
			level_number_text->show();
			score_text->show();
			time_complexity_text->show();
			operation_text->show();
		}
		void GamePlayUIController::createText()
		{
			level_number_text = new TextView();
			score_text = new TextView();
			time_complexity_text = new TextView();
			operation_text = new TextView();
		}
		void GamePlayUIController::initializeTexts()
		{
			initializeLevelNumberText();
			initializeScoreText();
			initializeTimeComplexityText();
			initializeOperationText();
		
		}
		void GamePlayUIController::initializeLevelNumberText()
		{
			level_number_text->initialize("Level : 1", sf::Vector2f(level_number_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}
		void GamePlayUIController::initializeScoreText()
		{
			score_text->initialize("Score : 0", sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}
		void GamePlayUIController::updateLevelNumberText()
		{
			LevelNumber level_number = ServiceLocator::getInstance()->getLevelService()->getCurrentLevel();
			sf::String level_number_value = std::to_string(1 + static_cast<int>(level_number));
			level_number_text->setText("Level : " + level_number_value);
			level_number_text->update();
		}
		void GamePlayUIController::updateScoreText()
		{
			int score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
			sf::String score_value = std::to_string(score);
			score_text->setText("Score : " + score_value);
			score_text->update();
		}
		void GamePlayUIController::destroy()
		{
			delete(level_number_text);
			delete(score_text);
		}
		void GamePlayUIController::initializeTimeComplexityText()
		{
			time_complexity_text->initialize("None", sf::Vector2f(time_complexity_text_x_position, time_complexity_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
		}
		void GamePlayUIController::initializeOperationText()
		{
			operation_text->initialize("None", sf::Vector2f(operations_text_x_position, operations_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
		}
		void GamePlayUIController::updateTimeComplexityText()
		{
			TimeComplexity time_complexity = ServiceLocator::getInstance()->getPlayerService()->getTimeComplexity();
			sf::String time_complexity_value;

			switch (time_complexity)
			{
			case Player::TimeComplexity::NONE:
				time_complexity_value = "";
				break;
			case Player::TimeComplexity::ONE:
				time_complexity_value = "1";
				break;
			case Player::TimeComplexity::N:
				time_complexity_value = "N";
				break;
			}

			time_complexity_text->setText("Time Complexity : " + time_complexity_value);
			time_complexity_text->update();
		}
		void GamePlayUIController::updateOperationText()
		{
			LinkListOperations link_list_operation = ServiceLocator::getInstance()->getPlayerService()->getLinkListOperation();
			sf::String link_list_operation_value;

			switch (link_list_operation)
			{
			case Player::LinkListOperations::NONE:
				link_list_operation_value = "";
				break;
			case Player::LinkListOperations::INSERT_AT_HEAD:
				link_list_operation_value = "Insert at Head";
				break;
			case Player::LinkListOperations::INSERT_AT_TAIL:
				link_list_operation_value = "Insert at Tail";
				break;
			case Player::LinkListOperations::INSERT_AT_MID:
				link_list_operation_value = "Insert at Middle";
				break;
			case Player::LinkListOperations::REMOVE_AT_HEAD:
				link_list_operation_value = "Remove From Head";
				break;
			case Player::LinkListOperations::REMOVE_AT_TAIL:
				link_list_operation_value = "Remove From Tail";
				break;
			case Player::LinkListOperations::REMOVE_AT_MID:
				link_list_operation_value = "Remove From Middle";
				break;
			case Player::LinkListOperations::DELETE_HALF_LIST:
				link_list_operation_value = "Delete Half List";
				break;
			case Player::LinkListOperations::REVERSE_LIST:
				link_list_operation_value = "Reverse List";
				break;
			}

			operation_text->setText("Last Operation : " +link_list_operation_value);
			operation_text->update();
		}
	}
}