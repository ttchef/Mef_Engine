
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

#include "../Utils.hpp"
#include "mef_circle.hpp"


namespace mef
{

    Circle::Circle()
    {
        m_radius = 10.0f;
        createObj();
    }

    Circle::Circle(uint16_t radius)
        : m_radius(radius)
    {
        createObj();
    }

    void Circle::setPos(mef::point2f pos)
    {
        m_pos = pos;
    }

    void Circle::setRadius(uint16_t radius)
    {
        m_radius = radius;
    }

    void Circle::createObj()
    {

        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
        
        std::string vertexShaderStr = mef::loadShader(m_vertexPath);
        std::string fragmentShaderStr = mef::loadShader(m_fragmentPath);

        const char* vertexShader = vertexShaderStr.c_str();
        const char* fragmentShader = fragmentShaderStr.c_str();

        glShaderSource(vShader, 1, &vertexShader, NULL);
        glShaderSource(fShader, 1, &fragmentShader, NULL);

        glCompileShader(vShader);
        mef::printShaderLog(vShader);
        glCompileShader(fShader);
        mef::printShaderLog(fShader);
        
        m_program = glCreateProgram();
        glAttachShader(m_program, vShader);
        glAttachShader(m_program, fShader);
        glLinkProgram(m_program);

    }

    void Circle::display(double deltaTime, uint16_t width, uint16_t height)
    {
        glBindVertexArray(m_VAO);
        glUseProgram(m_program);
        // Time
        float time = static_cast<float>(glfwGetTime());
        int loc = glGetUniformLocation(m_program, "uTime");
        glUniform1f(loc, time);

        // Resolution
        int loc_width = glGetUniformLocation(m_program, "uWidth");
        int loc_height = glGetUniformLocation(m_program, "uHeight");
        glUniform1f(loc_width, width);
        glUniform1f(loc_height, height);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
    }

}

