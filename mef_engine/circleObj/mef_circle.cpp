
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
        glPointSize(30.0f);

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
        glCompileShader(fShader);
        
        m_program = glCreateProgram();
        glAttachShader(m_program, vShader);
        glAttachShader(m_program, fShader);
        glLinkProgram(m_program);

    }

    void Circle::display(double deltaTime)
    {
        glBindVertexArray(m_VAO);
        glUseProgram(m_program);
        glDrawArrays(GL_POINTS, 0, 1);;
    }

}

