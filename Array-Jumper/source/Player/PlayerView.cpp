#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;


	PlayerView::PlayerView()
	{
		gameWindow = nullptr;
		playerImage = new ImageView();
	}

	PlayerView::~PlayerView()
	{
		delete(playerImage);
	}

	void PlayerView::Initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}

	void PlayerView::LoadPlayer()
	{
		calculatePlayerDimensions();
		InitializePlayerImage();
	}

	void PlayerView::Update()
	{
		UpdatePlayerPosition();
	}

	void PlayerView::Render()
	{
		DrawPlayer();
	}

	void PlayerView::InitializePlayerImage()
	{
		playerImage->initialize(Config::character_texture_path, playerWidth, playerHeight, sf::Vector2f(0, 0));
	}
	void PlayerView::DrawPlayer()
	{
	}

	void PlayerView::calculatePlayerDimensions()
	{
		playerWidth = 1000.f;
		playerHeight = 1000.f;
	}

	void PlayerView::UpdatePlayerPosition()
	{
		playerImage->setPosition(calculatePlayerPosition());
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		return sf::Vector2f(0, 0);

	}
}