#include "../../header/Level/LevelModel.h"

namespace Level
{
	Level::LevelModel::LevelModel()
	{
	}
	LevelModel::~LevelModel()
	{
	}
	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return level_configuration.levels[currentPosition].level_boxes[currentPosition];
	}
	void LevelModel::nextLevel()
	{
		current_level_index++;
	}
	int LevelModel::getCurrentLevelIndex()
	{
		return current_level_index + 1;
	}
	bool LevelModel::isLastLevel()
	{
		if (current_level_index == LevelConfiguration::number_of_levels - 1)
		{
			return true;
		}
		return false;
	}
	void LevelModel::reset()
	{
		current_level_index = 0;
	}
}