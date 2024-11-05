#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
namespace Level
{
	Level::LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView(this);
	}
	LevelController::~LevelController()
	{
		delete(level_model);
		delete(level_view);
	
	}
	void LevelController::initialize()
	{
		level_view->initilaize();
	}
	void LevelController::update()
	{
		level_view->update();
	}
	void LevelController::render()
	{
		level_view->render();
	}
	BlockType LevelController::getCurrentBoxValue(int currentPosion)
	{
		return level_model->getCurrentBoxValue(currentPosion);
	}
	BoxDimension LevelController::getBoxDimension()
	{
		return level_view->getBoxDimension();
	}
}