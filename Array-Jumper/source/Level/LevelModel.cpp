#include "../../header/Level/LevelModel.h"
#include <iostream>

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
		std::cout << currentPosition << std::endl;
		return level_configuration.levels[current_level_index].level_boxes[currentPosition];
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