#pragma once
#include "../../header/Level/LevelData.h"
#include "../../header/Level/LevelConfiguration.h"
namespace Level
{
	struct BoxDimension
	{
		float box_width;
		float box_height;

		float box_spacing;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.f;

	};
	class LevelModel
	{
	public:
		LevelModel();
		~LevelModel();

		BlockType getCurrentBoxValue(int currentPosition);
		void nextLevel();
		int getCurrentLevelIndex();
		bool isLastLevel();
		void reset();

	private:
		int current_level_index = 0;
		LevelConfiguration level_configuration;
	};


}