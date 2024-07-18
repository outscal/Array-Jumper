#pragma once
#include "../../header/Player/MovementDirection.h"
#include"../../header/Event/EventService.h"
namespace Player
{
	class EventService;
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	class PlayerController
		
	{
	private:
		Event::EventService* event_service;
		PlayerModel* player_model;
		PlayerView* player_view;

		void destroy();
		void resetPlayer();

	public:
		PlayerController();
		~PlayerController();
		void readInput();
		void initialize();
		void update();
		void render();
		bool isPositionInBound(int targetPosition);
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		void move(MovementDirection direction);
		int getCurrentPosition();
	};
}
