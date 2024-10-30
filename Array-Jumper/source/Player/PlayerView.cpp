#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
namespace Player
{
	using namespace Global;

	Player::PlayerView::PlayerView()
	{
		game_window = nullptr;
		player_image = new UI::UIElement::ImageView();
	}
	PlayerView::~PlayerView()
	{
	}
	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadImage();
	}
	void PlayerView::update()
	{
		updatePlayerPosition();
	}
	void PlayerView::render()
	{
		drawPlayer();
	}
	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0, 0));
	}
	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
	void PlayerView::loadImage()
	{
		calculatePlayerDimension();
		initializePlayerImage();
	}
	void PlayerView::calculatePlayerDimension()
	{
		player_width = 1000.f;
		player_height = 1000.f;
	}
	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}
	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		return sf::Vector2f(0,0);
	}
}