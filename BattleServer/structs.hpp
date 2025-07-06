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
};

struct P_STATE
{
	bool isAlive = true;
	bool isCasting = false;
};

