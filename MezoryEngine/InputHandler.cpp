#include "InputHandler.hpp"

int InputHandler::EnginePollEvent(GLFWwindow* window, EngineEvent* ev)
{
    glfwPollEvents();

    ev->state = glfwGetKey(window, GLFW_KEY_Z);
    if (ev->state == GLFW_PRESS)
    {
        ev->state = GLFW_PRESS;
        ev->key = GLFW_KEY_Z;
        return 1;
    }
   

    return GLFW_KEY_UNKNOWN;
}
