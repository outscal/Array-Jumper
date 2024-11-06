#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	namespace GameOverUI
	{
		class GameOverController
		{
		private:

			// Constants:
			const sf::String game_title = "Outscal Presents - Array Jumper";
			const sf::String game_over_text = "Game Over";
			const float background_alpha = 85.f;

			const float text_top_offset = 260.f;
			const int font_size = 110;
			const sf::Color text_color = sf::Color::White;

			const float button_width = 400.f;
			const float button_height = 140.f;
			const float menu_button_y_position = 600.f;
			const float quit_button_y_position = 800.f;

			// UI Elements:
			UI::UIElement::ImageView* background_image;
			UI::UIElement::TextView* title_text;
			UI::UIElement::TextView* gameover_text;
			UI::UIElement::ButtonView* menu_button;
			UI::UIElement::ButtonView* quit_button;

			void createText();
			void createImage();
			void createButtons();

			void initializeText();
			void initializeBackgroundImage();
			void initializeButtons();

			void registerButtonCallback();

			void menuButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			GameOverController();
			~GameOverController();

			void initialize();
			void update();
			void render();
			void show();
		};


	}
}
