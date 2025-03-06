#include <GLFW/glfw3.h>
#include <iostream>

void renderScene() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
    glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, -0.5, 0.0);
    glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
    glColor3f(1.0, 1.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow *window = glfwCreateWindow(800, 600, "WebGL-like OpenGL", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        renderScene();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}