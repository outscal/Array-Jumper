#pragma once
#include "BlockType.h"
#include "../../header/Level/LevelModel.h"
namespace Level
{
	class LevelModel;
	class LevelView;
	class LevelController
	{
	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BlockType getCurrentBoxValue(int currenPosition);
		BoxDimension getBoxDimension();
		bool isLastLevel();
		void nextLevel();
		void getCurrentLevelIndex();
		void reset();

	private:
		LevelModel* level_model;
		LevelView* level_view;
	};
}