#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "LevelModel.h"
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

		void calculateBoxWidthHeightDimension();
		void calculateBoxSpacing();
		void calcuateBoxDimension();
		sf::Vector2f calculateBoxPosition(int index);
		UI::UIElement::ImageView* getBoxImage(BlockType type);

		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlockType type);



	private:
		LevelController* level_controller;
		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		sf::RenderWindow* game_window;

		const float background_alpha = 110.f;

		BoxDimension box_dimension;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		void  createImage();
		void initilizeImage();
		void updateImage();
		void drawImage();
		void deleteImage();
	};

}