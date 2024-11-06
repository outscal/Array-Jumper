#pragma once
namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	public:

		int getPosition();
		void setPosition(int player_position);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		void resetPlayer();
	private:
		int current_position;
		PlayerState player_state;

	};


}