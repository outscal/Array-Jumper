#pragma once
#include "../../header/Level/BlockType.h"
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelConfiguration
	{
	public:
		static const int number_of_levels = 3;
		LevelData levels[number_of_levels];
		LevelConfiguration() {

			for (int i = 0; i < LevelData::number_of_box; i++)
			{
				levels[0].level_boxes[i] = level_1[i];
			}

			for (int i = 0; i < LevelData::number_of_box; i++)
			{
				levels[1].level_boxes[i] = level_2[i];
			}
			for (int i = 0; i < LevelData::number_of_box; i++)
			{
				levels[2].level_boxes[i] = level_3[i];
			}
		};

	private:
		BlockType level_1[LevelData::number_of_box] =
		{
			BlockType::ONE, BlockType::TWO, BlockType::OBSTACLE_ONE, BlockType::TWO, BlockType::THREE, BlockType::ONE, BlockType::OBSTACLE_TWO, BlockType::TWO, BlockType::ONE, BlockType::TARGET
		};

		BlockType level_2[LevelData::number_of_box] =
		{
			BlockType::ONE, BlockType::TWO, BlockType::OBSTACLE_TWO, BlockType::ONE, BlockType::TWO, BlockType::OBSTACLE_ONE, BlockType::THREE, BlockType::OBSTACLE_ONE, BlockType::ONE, BlockType::TARGET
		};

		BlockType level_3[LevelData::number_of_box] =
		{
			BlockType::ONE, BlockType::THREE, BlockType::OBSTACLE_ONE, BlockType::OBSTACLE_TWO, BlockType::ONE, BlockType::TWO, BlockType::OBSTACLE_ONE, BlockType::TWO, BlockType::ONE, BlockType::TARGET
		};
	};
}
