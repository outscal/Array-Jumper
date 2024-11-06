#include "../../header/UI/GamePlay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"

namespace GamePlayUI
{
	using namespace Global;
	using namespace UI::UIElement;
	GameplayUIController::GameplayUIController()
	{
		m_liveTextView = nullptr;
		createLiveTextView();
	}
	GameplayUIController::~GameplayUIController()
	{
		delete(m_liveTextView);
	}
	void GameplayUIController::initialize()
	{
		initializeLiveTextView();
	}
	void GameplayUIController::update()
	{
		updateLiveTextView();
	}
	void GameplayUIController::render()
	{
		m_liveTextView->render();
	}
	void GameplayUIController::createLiveTextView()
	{
		m_liveTextView = new UI::UIElement::TextView();
	}
	void GameplayUIController::initializeLiveTextView()
	{
		float window_width = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
		float x_position = window_width - right_offset;
		float y_position = top_offset;
		m_liveTextView->initialize("0", sf::Vector2f(x_position, y_position), UI::UIElement::FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
	}
	void GameplayUIController::updateLiveTextView()
	{
		int lives = ServiceLocator::getInstance()->getPlayerService()->getCurrentLives();
		std::string life_count_string = "LIFE: " + std::to_string(lives);

		m_liveTextView->setText(life_count_string);
		m_liveTextView->update();
	}
}