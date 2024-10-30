#pragma once
#include "../../header/UI/UIElement/ImageView.h"
namespace Level
{
	class LevelController;
	class LevelView
	{
	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initilaize();
		void update();
		void render();

	
		



	private:
		LevelController* level_controller;
		UI::UIElement::ImageView* background_image;
		sf::RenderWindow* game_window;

		const float background_alpha = 110.f;

		void  createImage();
		void initilizeImage();
		void updateImage();
		void drawImage();
		void deleteImage();
	};

}