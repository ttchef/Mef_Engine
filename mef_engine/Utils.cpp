

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "Utils.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

    void printShaderLog(unsigned int shader)
    {
        int len = 0;
        int chWritten = 0;
        char* log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        if (len > 0)
        {
            log = (char*)malloc(len);
            glGetShaderInfoLog(shader, len, &chWritten, log);
            std::cout << "Shader Info Log: " << log << std::endl;
            free(log);
        }
    }
}

