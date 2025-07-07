#include "pch.h"
#include "Player.hpp"
#include "Session.hpp"
#include "structs.hpp"

Player::Player(std::string id, std::shared_ptr<Session> session)
	: id_(id)
	, session_(session)
{
	STAT = { 100, 50 };
	POS = { 0.f , 0.f , 0.f };
	STATE = { true, false };	// ALIVE , CASTING
}

void Player::PushInput(const P_INPUT& input)
{
	inputQueue.push(input);
}

void Player::Update(float deltaTime)
{
	if (!STATE.isAlive || !canMove_) return;
	if (inputQueue.empty()) return;

	auto input = inputQueue.front();
	inputQueue.pop();

	switch (input.moveDir) {
		case MoveDir::UP:		POS.y += deltaTime * 3.f; break;
		case MoveDir::DOWN:		POS.y -= deltaTime * 3.f; break;
		case MoveDir::LEFT:		POS.x -= deltaTime * 3.f; break;
		case MoveDir::RIGHT:	POS.x += deltaTime * 3.f; break;
		default: break;
	}

	if (input.castPressed) {
		STATE.isCasting = true;
		// Skill ID -> Send FSM Event
	}
	else {
		STATE.isCasting = false;
	}
}

void Player::ApplyDamage(int amount)
{
	if (!STATE.isAlive) return;
	STAT.hp -= amount;
	if (STAT.hp <= 0)
	{
		STAT.hp = 0;
		STATE.isAlive = false;
	}
}

void Player::Reset()
{
	STAT = { 100, 50 };
	POS = { 0.f, 0.f, 0.f };
	STATE = { true, false };
}

void Player::SetAlive(bool val)
{
	STATE.isAlive = val;
}

void Player::SetMoveEnabled(bool enabled)
{
	canMove_ = enabled;
}

std::string Player::GetId() const
{
	return id_;
}

P_POS Player::GetPosition() const
{
	return POS;
}

bool Player::IsAlive() const
{
	return STATE.isAlive;
}

std::shared_ptr<Session> Player::GetSession()
{
	return session_;
}

