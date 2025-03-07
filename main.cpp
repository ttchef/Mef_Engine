#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <mef.hpp>
#include <iostream>

// Diese Funktion wird aufgerufen, wenn die Fenstergröße geändert wird
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    Console::print("Starting application");
    
    // GLFW initialisieren
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    
    // OpenGL-Version und -Profil konfigurieren
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // oder eine niedrigere Version, falls nötig
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Fenster erstellen
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    // OpenGL-Kontext aktivieren
    glfwMakeContextCurrent(window);
    
    // Callback für Fenstergrößenänderungen registrieren
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Glad laden: OpenGL-Funktionen laden
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // OpenGL-Viewport setzen
    glViewport(0, 0, 800, 600);
    
    // Hintergrundfarbe setzen (dunkelblau)
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    // Render-Loop
    while (!glfwWindowShouldClose(window)) {
        // Eingabe verarbeiten
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        // Rendering
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Buffers austauschen und Events prüfen
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Aufräumen
    glfwTerminate();
    return 0;
}

