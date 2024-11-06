#pragma once
#include "../../header/Event/EventService.h"
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
		void jump(MovementDirection direction);
		bool isPositionValid(int targetPosition);

		void readInput();
		
		int getCurrentPosition();
		void takeDamage();

		int getCurrentLives();
		void onDeath();
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;

		
	};
}