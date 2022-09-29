#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace InputHandler
{
    struct EngineEvent
    {
        int state;
        int key;
    };

/**
* @brief Poll for currently pending events.
*
* @param ev The event structure to be filled with the next event
* @return 1 if there is a pending event or -1 if there are none available.
*/
    int EnginePollEvent(GLFWwindow *window, EngineEvent *ev);

}

#endif // !INPUT_HANDLER_HPP