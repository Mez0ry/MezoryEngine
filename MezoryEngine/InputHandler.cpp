#include "InputHandler.hpp"

int InputHandler::EnginePollEvent(GLFWwindow* window, EngineEvent* ev)
{
    glfwPollEvents();
    const int keys_size = 350;

    for (int key = 0; key < keys_size; key++) {
        ev->state = glfwGetKey(window, key);

        glfwGetCursorPos(window, &ev->mouse_pos.x, &ev->mouse_pos.y);

        if (ev->state == GLFW_PRESS)
        {
            ev->state = GLFW_PRESS;
            ev->key = key;
            return 1;
        }
        if (ev->state == GLFW_RELEASE) {
            ev->state = GLFW_RELEASE;
            ev->key = key;
         }
    }

    ev->state = -1;
    ev->key = -1;
    return GLFW_KEY_UNKNOWN;
}
