#include "OpenglContext.hpp"

OpenglContext::OpenglContext() : pWindow_(nullptr)
{
}

OpenglContext::~OpenglContext()
{
	glfwDestroyWindow(pWindow_);
	glfwTerminate();
}
 
void OpenglContext::Initialize()
{
	__exception_data ex_data{};

	try {

		if (!glfwInit()) {
			ex_data.code_ = glfwGetError(&ex_data.what_);
			throw init_error(ex_data.what_, ex_data.code_);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		pWindow_ = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "BounceBall game", nullptr, nullptr);

		if (!pWindow_) {
			ex_data.what_ = "glfw failed, window not created";
			throw init_error(ex_data.what_, ex_data.code_);
		}

		glfwMakeContextCurrent(pWindow_);
		
		if (!gladLoadGL()) {
			ex_data.what_ = "Failed to initialize OpenGL context";
			ex_data.code_ = -1;
			throw init_error(ex_data.what_, ex_data.code_);
		}
	}
	catch(const init_error& ex){
		std::cout << ex.what() << static_cast<char>('\n') << "Error code: " << ex.err_code() << '\n';
	}


}
