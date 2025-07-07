#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool get_json(json& ctx)
{
    std::ifstream configFile("config/config.json");
    if (!configFile.is_open()) {
        std::cerr << "config.json ������ �� �� �����ϴ�." << std::endl;
        return false;
    }
    try
    {
        configFile >> ctx;
    }
    catch (const std::exception& e)
    {
        std::cout << "json �۾� ���� : " << e.what() << std::endl;
        return false;
    }

    return true;
}