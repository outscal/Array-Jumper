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

		BlockType getCurrentBoxValue(int currentPosion);
		BoxDimension getBoxDimension();

	private:
		LevelModel* level_model;
		LevelView* level_view;
	};
}