#pragma once
#include "structs.hpp"
class Session;

class Player
{
public:
	void PushInput(const P_INPUT& input);
	void Update(float deltaTime);
	void ApplyDamage(int amount);
	void Reset();
	void SetAlive(bool val);

	std::string GetId() const;
	P_POS GetPosition() const;
	bool IsAlive() const;

	std::shared_ptr<Session> GetSession();
	void SetMoveEnabled(bool enabled);

private:
	P_AUTH_INFO AUTH;
	P_STAT STAT;
	P_POS POS;
	P_STATE STATE;
public:
	Player();
	Player(std::string id, std::shared_ptr<Session> session);
};

