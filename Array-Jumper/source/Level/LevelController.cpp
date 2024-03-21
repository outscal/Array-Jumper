#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Main/GameService.h"

namespace Level
{

	LevelController::LevelController()
	{
		level_view = new LevelView(this);
		level_model = new LevelModel();
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BoxDimentions LevelController::getBoxDimentions()
	{
		return level_view->getBoxDimentions();
	}

	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getCurrentBoxValue(currentPosition);
	}

}