

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "Utils.hpp"

namespace mef
{
    std::string loadShader(const char* filePath)
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "[MEF_ENGINE ERROR] Couldnt Open Shader Files! " << filePath << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
}

