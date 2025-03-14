namespace mef
{
    class Circle
    {
    public:
        Circle();
        Circle(uint16_t radius);

        void display(double deltaTime);

        void setPos(mef::point2f pos);
        void setRadius(uint16_t radius);

        // Getters
        uint16_t getRadius() { return m_radius; }
        mef::point2f getPos() { return m_pos; }
    private:
        uint16_t m_radius;
        mef::point2f m_pos;

        unsigned int m_VAO;
        unsigned int m_program;

        const char* m_fragmentPath = "../../../mef_engine/circleObj/mef_circle_shader.frag";
        const char* m_vertexPath = "../../../mef_engine/circleObj/mef_circle_shader.vert";

        // Functions
        void createObj();
    };
}

