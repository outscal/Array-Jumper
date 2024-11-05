#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/Movement.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Level/BlockType.h"
#include <iostream>

namespace Player
{
	using namespace Level;
	using namespace Global;
	using namespace Sound;
	Player::PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}
	Player::PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}
	void PlayerController::initialize()
	{

		player_view->initialize();
		event_service = ServiceLocator::getInstance()->getEventService();

	}
	void PlayerController::update()
	{
		readInput();
		player_view->update();

	}
	void PlayerController::render()
	{
		player_view->render();
	}
	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}
	void PlayerController::setPlayerState(PlayerState state)
	{
		player_model->setPlayerState(state);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->getPosition();
	}

	void PlayerController::movePlayer(MovementDirection direction)
	{
		int steps, targetPosition;

		switch (direction)
		{
		case Player::MovementDirection::FORWARD:
			steps = 1;

			break;
		case Player::MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->getPosition() + steps;

		if (!isPositionValid(targetPosition))
		{
			return;
		}

		player_model->setPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}

    void PlayerController::jump(MovementDirection direction)
    {
        int currentPosition = player_model->getPosition();
        BlockType box_value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(currentPosition);
        int steps, targetPosition;
        switch (direction)
        {
        case Player::MovementDirection::FORWARD:
            steps = static_cast<int>(box_value); 
            break;
        case Player::MovementDirection::BACKWARD:
            steps = -static_cast<int>(box_value); 
            break;
        default:
            steps = 0;
            break;
        }
        targetPosition = currentPosition + steps;
        if (isPositionValid(targetPosition))
        {
            player_model->setPosition(targetPosition);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
        }
    }

	bool PlayerController::isPositionValid(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < Level::LevelData::number_of_box)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::BACKWARD);
			}
			else
			{
				movePlayer(MovementDirection::BACKWARD);
			}
		}
		else if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::FORWARD);
			}
			else
			{
				movePlayer(MovementDirection::FORWARD);
			}
		}

	}

}
