#pragma once
#include "LevelController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelController.h"

namespace Level
{
	class LevelView
	{
	private:

		sf::RenderWindow* game_window;
		LevelController* level_controller;

		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;
		
		const float background_alpha = 110.f;
		BoxDimensions box_dimensions;

		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();
		UI::UIElement::ImageView* getBoxOverlayImage(BlockType block_type);
		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlockType box_value);
		sf::Vector2f calculateBoxPosition(int index);
	public:
		BoxDimensions getBoxDimensions();
		LevelView(LevelController* controller);
		~LevelView();
		void calculateBoxWidthHeight();
		void calculateBoxDimensions();
		void calculateBoxSpacing();
		void initialize();
		void update();
		void render();
	};
}
