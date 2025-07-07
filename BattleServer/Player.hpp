#pragma once
#include "structs.hpp"
class Session;

class Player
{
public:
	// input & sync
	void PushInput(const P_INPUT& input);
	void Update(float deltaTime);

	// state
	void ApplyDamage(int amount);
	void Reset();
	void SetAlive(bool val);
	void SetMoveEnabled(bool enabled);

	// get, set
	std::string GetId() const;
	P_POS GetPosition() const;
	bool IsAlive() const;
	std::shared_ptr<Session> GetSession();

private:
	std::string id_;
	std::shared_ptr<Session> session_;

	P_AUTH_INFO AUTH;
	P_STAT STAT;
	P_POS POS;
	P_STATE STATE;

	bool canMove_ = true;

	std::queue<P_INPUT> inputQueue;
public:
	Player(std::string id, std::shared_ptr<Session> session);
};

