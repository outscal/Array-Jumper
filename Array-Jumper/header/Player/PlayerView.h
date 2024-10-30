#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerView
	{
	public:
		PlayerView();
		~PlayerView();

		void initialize();
		void update();
		void render();

	
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadImage();
		void calculatePlayerDimension();
		void updatePlayerPosition();

		sf::Vector2f calculatePlayerPosition();

	};


}