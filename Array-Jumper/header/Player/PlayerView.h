#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerView
	{
	private:
		sf::RenderWindow* gameWindow;
		UI::UIElement::ImageView* playerImage;

		float playerHeight;
		float playerWidth;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void calculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView();
		~PlayerView();

		void Initialize();
		void Update();
		void Render();

		
	};
}