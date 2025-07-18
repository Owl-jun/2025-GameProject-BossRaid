#pragma once
#include "structs.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool get_json(json& ctx)
{
    std::ifstream configFile("config/config.json");
    if (!configFile.is_open()) {
        std::cerr << "config.json 파일을 열 수 없습니다." << std::endl;
        return false;
    }
    try
    {
        configFile >> ctx;
    }
    catch (const std::exception& e)
    {
        std::cout << "json 작업 실패 : " << e.what() << std::endl;
        return false;
    }

    return true;
}

inline float Distance(const P_POS& a, const P_POS& b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline std::string MakePacket(uint8_t opcode, std::string msg)
{
    return std::string();
}