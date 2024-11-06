#include "../../header/UI/GamePlay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"

namespace GamePlayUI
{
	using namespace Global;
	using namespace UI::UIElement;
	GameplayUIController::GameplayUIController()
	{
		m_liveTextView = nullptr;
		createTextView();
	}
	GameplayUIController::~GameplayUIController()
	{
		delete(m_liveTextView);
	}
	void GameplayUIController::initialize()
	{
		initializeTextView();
	}
	void GameplayUIController::update()
	{
		updateTextView();
	}
	void GameplayUIController::render()
	{
		m_liveTextView->render();
	}
	void GameplayUIController::createTextView()
	{
		m_liveTextView = new UI::UIElement::TextView();
		m_levelTextView = new UI::UIElement::TextView();
	}
	void GameplayUIController::initializeTextView()
	{
		float window_width = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
		float x_position = window_width - right_offset;
		float y_position = top_offset;
		m_liveTextView->initialize("0", sf::Vector2f(x_position, y_position), UI::UIElement::FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
		m_levelTextView->initialize("0", sf::Vector2f(left_offset, y_position), UI::UIElement::FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
	}
	void GameplayUIController::updateTextView()
	{
		int level = ServiceLocator::getInstance()->getLevelService()->getCurrentLevelIndex();
		std::string level_count_string = "LEVEL: " + std::to_string(level);

		int lives = ServiceLocator::getInstance()->getPlayerService()->getCurrentLives();
		std::string life_count_string = "LIFE: " + std::to_string(lives);

		m_levelTextView->setText(level_count_string);
		m_liveTextView->setText(life_count_string);
		m_levelTextView->update();
		m_liveTextView->update();
	}

	
}