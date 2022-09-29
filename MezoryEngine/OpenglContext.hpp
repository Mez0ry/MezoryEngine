#ifndef BounceBall_OPENGL_CONTEXT_HPP
#define BounceBall_OPENGL_CONTEXT_HPP
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "init_error.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

class OpenglContext
{
public:
	OpenglContext();
	~OpenglContext();
/**
* @brief initializing GLFW & GLAD
*/
	void Initialize();

	_NODISCARD  GLFWwindow* const get_window() const noexcept { return pWindow_; }
private:
	GLFWwindow* pWindow_ = nullptr;
 
};

#endif // !BounceBall_OPENGL_CONTEXT_HPP