#include "../../header/Level/LevelModel.h"

namespace Level
{
	Level::LevelModel::LevelModel()
	{
	}
	LevelModel::~LevelModel()
	{
	}
	BlockType LevelModel::getCurrentBoxValue(int currentPosion)
	{
		return current_level_data.level_boxes[currentPosion];
	}
}