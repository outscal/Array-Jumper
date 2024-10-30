#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{
	Player::PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}
	Player::PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}
	void PlayerController::initialize()
	{
		player_view->initialize();
		
	}
	void PlayerController::update()
	{
		player_view->update();

	}
	void PlayerController::render()
	{
		player_view->render();
	}
	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}
	void PlayerController::setPlayerState(PlayerState state)
	{
		player_model->setPlayerState(state);
	}
}