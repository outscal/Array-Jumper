#pragma once
#include "../../header/Level/BlockType.h"

namespace GamePlay
{

	class GamePlayController
	{
	public:
		GamePlayController();
		~GamePlayController();

		void initialize();
		void update();
		void render();

	private:
		void processObstacle();
		bool isCollidingWithObstacle(BlockType value);
		void onPositionChanged(int position);
		bool isEndBlock(BlockType value);
		void processEndBlock();
	};


}