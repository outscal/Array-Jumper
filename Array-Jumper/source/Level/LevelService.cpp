#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
namespace Level
{
	Level::LevelService::LevelService()
	{
		level_controller = new LevelController();
	}
	LevelService::~LevelService()
	{
		delete(level_controller);
	}
	void LevelService::initialize()
	{
		level_controller->initialize();
	}
	void LevelService::update()
	{
		level_controller->update();
	}
	void LevelService::render()
	{
		level_controller->render();
	}
	BoxDimension LevelService::getBoxDimension()
	{
		return level_controller->getBoxDimension();
	}
	BlockType LevelService::getCurrentBoxValue(int currentPosition)
	{
		return level_controller->getCurrentBoxValue(currentPosition);
	}
	bool LevelService::isLastLevel()
	{
		return level_controller->isLastLevel();
	}
	void LevelService::nextLevel()
	{
		level_controller->nextLevel();
	}
	int LevelService::getCurrentLevelIndex()
	{
		return level_controller->getCurrentLevelIndex();
	}
	void LevelService::reset()
	{
		level_controller->reset();
	}
}