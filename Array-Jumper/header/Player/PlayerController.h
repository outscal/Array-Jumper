#pragma once
namespace Player
{
	class PlayerModel;
	class PlayerView;
	class EventService;
	enum class PlayerState;
	enum class MovementDirection;

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


		void movePlayer(MovementDirection direction);
		bool isPositionValid(int targetPosition);

		void readInput();

	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;

		
	};
}