#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class playerModel
	{
	private:
		int currentPosition;
		PlayerState playerState;

	public:

		void SetPlayerState(PlayerState state);
		PlayerState GetPlayerState();

		void SetCurrentPosition(int position);
		int GetCurrentPosition();

	};
}
