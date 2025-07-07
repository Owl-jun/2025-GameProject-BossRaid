#pragma once

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