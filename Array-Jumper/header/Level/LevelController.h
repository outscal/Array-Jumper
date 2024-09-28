#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
	class LevelModel;
	class LevelView;

	class LevelController
	{
	private:
		LevelModel* levelModel;
		LevelView* levelView;

	public:
		LevelController();
		~LevelController();


		void Initialize();
		void Update();
		void Render();

		BlockType GetCurrentBoxValue(int currentPosition);
	};
}
