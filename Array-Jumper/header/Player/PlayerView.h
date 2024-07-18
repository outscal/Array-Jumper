#pragma once
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	
	class PlayerController;
	class PlayerView
		struct BoxDimensions;
   

	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;
		PlayerController* player_controller;
		BoxDimentions current_box_dimensions;

		float player_height ;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void CalculatePlayerDimensions();
		sf::Vector2f calulcatePlayerPosition();
		void CalculatePlayerDimensions();
	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}