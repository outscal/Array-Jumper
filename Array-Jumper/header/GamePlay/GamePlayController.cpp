#include "GamePlayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Level/LevelService.h"

using namespace Global;
using namespace Sound;
using namespace Level;


GamePlay::GamePlayController::GamePlayController()
{
}

GamePlay::GamePlayController::~GamePlayController()
{
}

void GamePlay::GamePlayController::initialize()
{
}

void GamePlay::GamePlayController::update()
{
	onPositionChanged(ServiceLocator::getInstance()->getPlayerService()->getCurrentPosition());
}

void GamePlay::GamePlayController::render()
{
}

void GamePlay::GamePlayController::processObstacle()
{
	ServiceLocator::getInstance()->getPlayerService()->takeDamage();
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
}

bool GamePlay::GamePlayController::isCollidingWithObstacle(BlockType value)
{
	if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
	{
		return true;
	}
	return false;
}

void GamePlay::GamePlayController::onPositionChanged(int position)
{
	BlockType block = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);
	if (isCollidingWithObstacle(block))
	{
		processObstacle();
	}
}
