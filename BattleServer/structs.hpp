#pragma once
#include <string>

struct P_AUTH_INFO 
{
	bool isAuth = false;
	std::string name;
	std::string token;
};

struct P_STAT
{
	int hp;
	int mp;
};

struct P_POS
{
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	P_POS operator+(const P_POS& other) const {
		return { x + other.x, y + other.y, z + other.z };
	}
	P_POS operator-(const P_POS& other) const {
		return { x - other.x, y - other.y, z - other.z };
	}
};

struct P_STATE
{
	bool isAlive = true;
	bool isCasting = false;
};

enum class MoveDir {NONE, UP, DOWN, LEFT, RIGHT};

struct P_INPUT
{
	MoveDir moveDir = MoveDir::NONE;
	bool castPressed = false;
	int skillId = -1;
	uint64_t timestamp = 0;
};

enum class PlayerState {
	IDLE,
	MOVING,
	CASTING,
	STUNNED,
	DEAD
};
