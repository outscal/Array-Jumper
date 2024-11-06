#include "../../header/Player/PlayerModel.h"


namespace Player {
	void PlayerModel::initialize()
	{
		current_lives = max_lives;
	}
	void PlayerModel::update()
	{
	}
	int PlayerModel::getPosition()
	{
		return current_position;
	}
	void PlayerModel::setPosition(int player_position)
	{
		current_position = player_position;
	}
	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}
	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}
	void PlayerModel::resetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
		current_lives = max_lives;
	}
	int PlayerModel::getCurrentLives()
	{
		return current_lives;
	}
	void PlayerModel::decrementLife()
	{
		current_lives--;
	}
	void PlayerModel::resetPositon()
	{
		current_position = 0;
	}
}