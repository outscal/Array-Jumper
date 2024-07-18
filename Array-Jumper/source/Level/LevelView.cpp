#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include"../../header/Level/LevelModel.h"

namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;
	

	LevelView::LevelView(LevelController* controller)
	{
		game_window = nullptr;
		level_controller = controller;
		createImages();
	}

	LevelView::~LevelView()
	{
		deleteImages();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		calculateBoxDimensions();
		initializeImages();
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::createImages()
	{
		box_image = new ImageView();
		background_image = new ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();
		
	}

	void LevelView::initializeImages()
	{
		box_image->initialize(Config::box_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
		target_overlay_image->initialize(Config::target_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
	}

	void LevelView::updateImages()
	{
		box_image->update();
		background_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}

	void LevelView::drawLevel()
	{
		box_image->render();
		background_image->render();
	}

	void LevelView::deleteImages()
	{
		delete(background_image);
		delete(box_image);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);
	}
	void LevelView::calculateBoxDimensions()
	{
		if (!game_window) return;
		box_dimensions.box_width = 300.f;
		box_dimensions.box_height = 300.f;
		
	}
	ImageView* LevelView::getBoxOverlayImage(Level::BlockType block_type)
	{
		switch (block_type)
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;

		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;

		case BlockType::ONE:
			return letter_one_overlay_image;

		case BlockType::TWO:
			return letter_two_overlay_image;

		case BlockType::THREE:
			return letter_three_overlay_image;

		case BlockType::TARGET:
			return target_overlay_image;
		}
		return nullptr;
	}
}