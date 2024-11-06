#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"
namespace Player
{
	Player::PlayerService::PlayerService()
	{
		player_conroller = new PlayerController();
	}
	PlayerService::~PlayerService()
	{
		delete(player_conroller);
	}
	void PlayerService::initialize()
	{
		player_conroller->initialize();
	}
	void PlayerService::update()
	{
		player_conroller->update();
	}
	void PlayerService::render()
	{
		player_conroller->render();
	}
	void PlayerService::takeDamage()
	{
		player_conroller->takeDamage();
	}
	int PlayerService::getCurrentPosition()
	{
		return player_conroller->getCurrentPosition();
	}
	void PlayerService::levelComplete()
	{
		player_conroller->takeDamage();
	}
}