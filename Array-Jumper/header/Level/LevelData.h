#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int number_of_box = 10;
		BlockType level_boxes[number_of_box] = {
			BlockType::ONE,
			BlockType::TWO,
			BlockType::OBSTACLE_ONE,
			BlockType::TWO,
			BlockType::THREE,
			BlockType::ONE,
			BlockType::OBSTACLE_TWO,
			BlockType::TWO,
			BlockType::ONE,
			BlockType::TARGET
		};



	};
}

