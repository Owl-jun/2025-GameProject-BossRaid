#include "pch.h"
#include "BattleRoom.hpp"
#include "Player.hpp"
#include "Boss.hpp"
#include "Timer.hpp"
#include "Session.hpp"

BattleRoom::BattleRoom(std::string roomId)
	: roomId_(roomId)
{
}

void BattleRoom::AddPlayer(std::shared_ptr<Player> player)
{
	players_.push_back(player);
}

void BattleRoom::RemovePlayer(std::string player_id)
{
	for (auto player : players_)
	{
		if (player->GetId() == player_id)
		{
			players_.erase(std::remove(players_.begin(), players_.end(), player));
		}
	}
}

void BattleRoom::Start()
{
	isBattleStarted = true;
}

void BattleRoom::Update(float deltaTime)
{
	if (!isBattleStarted) return;

	ProcessP_Input(deltaTime);
	UpdateBossAI(deltaTime);

	syncTimer += deltaTime;
	if (syncTimer >= syncInterval)
	{
		BroadcastState();
		syncTimer = 0.f;
	}

	CheckBattleEnd();
}

void BattleRoom::HandleInput(std::string player_id, const P_INPUT& input)
{

}

void BattleRoom::ProcessP_Input(float deltaTime)
{
	for (auto& player : players_)
	{
		player->Update(deltaTime);
	}
}

void BattleRoom::UpdateBossAI(float deltaTime)
{

}

void BattleRoom::BroadcastState()
{

}

void BattleRoom::CheckBattleEnd()
{

}

