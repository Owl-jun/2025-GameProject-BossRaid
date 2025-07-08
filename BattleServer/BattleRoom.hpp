#pragma once
#include "structs.hpp"

class Player;
class Boss;
class Timer;

class BattleRoom : public std::enable_shared_from_this<BattleRoom>
{
public:
	BattleRoom(std::string roomId);
	void AddPlayer(std::shared_ptr<Player> player);
	void RemovePlayer(std::string player_id);

	void Start();
	void Update(float deltaTime);
	void HandleInput(std::string player_id, const P_INPUT& input);

private:
	void ProcessP_Input(float deltaTime);
	void UpdateBossAI(float deltaTime);
	void BroadcastState();
	void CheckBattleEnd();

private:
	std::string roomId_;
	bool isBattleStarted = false;

	std::vector<std::shared_ptr<Player>> players_;
	std::shared_ptr<Boss> boss_;

	float syncTimer = 0.0f;
	const float syncInterval = 0.1f;

	std::shared_ptr<Timer> timer_;
};

