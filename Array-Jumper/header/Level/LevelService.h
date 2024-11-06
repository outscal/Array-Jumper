#pragma once
#include "BlockType.h"
namespace Level
{
	struct BoxDimension;
	class LevelController;
	class BoxType;
	class LevelService
	{
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		BoxDimension getBoxDimension();
		BlockType getCurrentBoxValue(int currentPosition);
		bool isLastLevel();
		void nextLevel();
		int getCurrentLevelIndex();
		void reset();

	private:
		LevelController* level_controller;
	};

}