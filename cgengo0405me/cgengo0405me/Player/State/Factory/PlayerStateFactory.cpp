#include "PlayerStateFactory.h"

#include "../StoppedState.h"
#include "../JumpingState.h"
#include "../RunningState.h"
#include "../../Player.h"

PlayerStateFactory* PlayerStateFactory::instance = nullptr;

void PlayerStateFactory::Initialize(class Player& player)
{
	idle = new StoppedState(&player);
	jump = new JumpingState(&player);
	run = new RunningState(&player);
}

void PlayerStateFactory::Finalize()
{
	instance->idle->Finalize();
	instance->jump->Finalize();
	instance->run->Finalize();
}

PlayerStateBase* PlayerStateFactory::Get(Player& player, ePlayerState state)
{
	if (instance == nullptr)
	{
		instance = new PlayerStateFactory();
		instance->Initialize(player);
	}

	PlayerStateBase* ret = nullptr;
	switch (state)
	{
		case ePlayerState::IDLE:
			 instance->idle->Initialize();
			 ret = instance->idle;
			 break;
		case ePlayerState::JUMP:
			 instance->jump->Initialize();
			 ret = instance->jump;
			 break;

		case ePlayerState::RUN:
			instance->run->Initialize();
			ret = instance->run;
			break;

		case ePlayerState::NONE:   //•Ô‚·‚à‚Ì‚È‚µ
		default:
			break;

	}
	return ret;
}
