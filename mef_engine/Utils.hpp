

#include <string>

namespace mef
{
    struct point2f
    {
        float x;
        float y;
    };

    std::string loadShader(const char* filePath);
    void printShaderLog(unsigned int shader);
}

