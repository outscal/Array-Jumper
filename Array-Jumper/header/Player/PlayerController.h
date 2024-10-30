#pragma once
namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class  PlayerController
	{
	public:
		 PlayerController();
		~ PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		
	};
}