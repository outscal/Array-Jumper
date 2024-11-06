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
		
		void initialize();
		void update();

		int current_lives;
		int getPosition();
		void setPosition(int player_position);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);
		void resetPlayer();

		int getCurrentLives();
		void decrementLife();
		void resetPositon();
	private:
		int current_position;
		const int max_lives = 3;
		PlayerState player_state;

	};


}