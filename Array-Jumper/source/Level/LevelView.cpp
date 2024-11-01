#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;

	Level::LevelView::LevelView(LevelController* controller)
	{
		level_controller = controller;
		game_window = nullptr;
		createImage();
	}
	LevelView::~LevelView()
	{
		deleteImage();
	}
	void LevelView::initilaize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initilizeImage();
	}
	void LevelView::update()
	{
		updateImage();
	}
	void LevelView::render()
	{
		drawImage();
	}
	void LevelView::calcuateBoxDimension()
	{
		if (!game_window) return;

		box_dimension.box_width = 300.f;
		box_dimension.box_height = 300.f;
	}
	ImageView* LevelView::getBoxImage(BlockType type)
	{
		switch (type)
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;
			break;
		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;
			break;
		case BlockType::TARGET:
			return target_overlay_image;
			break;
		case BlockType::ONE:
			return letter_one_overlay_image;
			break;
		case BlockType::TWO:
			return letter_two_overlay_image;
			break;
		case BlockType::THREE:
			return letter_three_overlay_image;
			break;
		}
	}
	void LevelView::drawBox(sf::Vector2f position)
	{
		box_image->setPosition(position);
		box_image->render();
	}
	void LevelView::drawBoxValue(sf::Vector2f position, BlockType type)
	{
		ImageView* image = getBoxImage(type);
		image->setPosition(position);
		image->render();
	}
	void LevelView::createImage()
	{
		background_image = new ImageView();
		box_image = new ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();


	}
	void LevelView::initilizeImage()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);

		box_image->initialize(Config::box_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		//target_overlay_image->initialize(Config::target_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
	}
	void LevelView::updateImage()
	{
		background_image->update();
		box_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}
	void LevelView::drawImage()
	{
		background_image->render();
		drawBox(sf::Vector2f(0, 0));
		BlockType blockTypeToDraw = level_controller->getCurrentBoxValue(0);
		drawBoxValue(sf::Vector2f(0, 0), blockTypeToDraw);
	
	}
	void LevelView::deleteImage()
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
}