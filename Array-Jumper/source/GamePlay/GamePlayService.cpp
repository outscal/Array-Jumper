#include "../../header/GamePlay/GamePlayService.h"
#include "../../header/GamePlay/GamePlayController.h"
#include "../../header/Global/ServiceLocator.h"
namespace GamePlay
{
	using namespace Global;
	GamePlay::GamePlayService::GamePlayService()
	{
		m_gamePlayController = new GamePlayController();
	}
	GamePlayService::~GamePlayService()
	{
		delete m_gamePlayController;
	}
	void GamePlayService::initialize()
	{
		m_gamePlayController->initialize();
	}
	void GamePlayService::update()
	{
		m_gamePlayController->update();
	}
	void GamePlayService::render()
	{
		m_gamePlayController->render();
	}

}