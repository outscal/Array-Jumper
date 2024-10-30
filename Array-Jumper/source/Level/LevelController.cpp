#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
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
}