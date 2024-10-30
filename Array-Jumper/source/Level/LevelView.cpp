#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
namespace Level
{
	using namespace Global;

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
	void LevelView::createImage()
	{
		background_image = new UI::UIElement::ImageView();
	}
	void LevelView::initilizeImage()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
	}
	void LevelView::updateImage()
	{
		background_image->update();
	}
	void LevelView::drawImage()
	{
		background_image->render();
	}
	void LevelView::deleteImage()
	{
		delete(background_image);
	}
}