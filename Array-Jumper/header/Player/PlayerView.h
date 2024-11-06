#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"

namespace Player
{
	using namespace Level;
	class PlayerController;
	class PlayerView
	{
	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();

		BoxDimension current_box_dimensions;
	
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;

		PlayerController* player_controller;

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