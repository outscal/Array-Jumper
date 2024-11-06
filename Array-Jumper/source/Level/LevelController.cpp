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
	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getCurrentBoxValue(currentPosition);
	}
	BoxDimension LevelController::getBoxDimension()
	{
		return level_view->getBoxDimension();
	}
	bool LevelController::isLastLevel()
	{
		return level_model->isLastLevel();
	}
	void LevelController::nextLevel()
	{
		level_model->nextLevel();
	}
	int LevelController::getCurrentLevelIndex()
	{
		return level_model->getCurrentLevelIndex();
	}

	void LevelController::reset()
	{
		level_model->reset();
	}
}