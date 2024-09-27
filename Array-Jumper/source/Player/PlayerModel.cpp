#include "../../header/Player/PlayerModel.h"

namespace Player
{
	void playerModel::SetPlayerState(PlayerState state)
	{
		playerState = state;
	}
	PlayerState playerModel::GetPlayerState()
	{
		return playerState;
	}
	void playerModel::SetCurrentPosition(int position)
	{
		currentPosition = position;
	}
	int playerModel::GetCurrentPosition()
	{
		return currentPosition;
	}
}