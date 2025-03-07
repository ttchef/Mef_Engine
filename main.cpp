
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <mef.hpp>
#include "stb_image.h"
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
    
    // GLM-Beispiel: Erstelle eine 4x4 Transformationsmatrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    
    // Hintergrundfarbe setzen (dunkelblau)
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    // Render-Loop
    while (!glfwWindowShouldClose(window)) {
        // Eingabe verarbeiten
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        // Rendering
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Hier würdest du deine Rendering-Befehle einfügen und
        // die GLM-Matrizen verwenden
        
        // Buffers austauschen und Events prüfen
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Aufräumen
    glfwTerminate();
    return 0;
}

