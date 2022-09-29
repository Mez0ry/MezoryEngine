#ifndef ShaderManager_HPP
#define ShaderManager_HPP
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class ShaderManager
{
private:
	bool isReady_ = false;
	GLuint programID_;
public:
	ShaderManager() = default;
	ShaderManager(const char* vs, const char* fs);
	~ShaderManager();
	
/**
* @brief Creates shader
* @return 1 on success and 0 on failure
*/
	int CreateShader(const char* source, const GLenum& shader_type, GLuint& id);

/**
* @brief Linking shaders
* @param programm_id - var where will be stored id of programm
* @param shader_args - shaders to be linked
* @return 1 on success and 0 on failure
*/
	template <typename ... Args>
	int LinkShader(GLuint& programm_id,const Args& ... shader_args);

/**
* @brief checks whether the shader is ready to use
*/
	bool isReady() const noexcept { return isReady_; }

	void UseProgram();

public:
	ShaderManager(const ShaderManager&) = default;
	ShaderManager(ShaderManager&& rhs) noexcept {

		if (this == &rhs) {
			return;
		}

		glDeleteProgram(programID_);

		programID_ = rhs.programID_;
		isReady_ = rhs.isReady_;
		rhs.isReady_ = false;
		rhs.programID_ = 0;
	}

	ShaderManager& operator=(const ShaderManager& rhs) {
		if (this == &rhs) {
			return *this;
		}

		if (programID_) {
			glDeleteProgram(programID_);
		}

		this->isReady_ = rhs.isReady_;
		this->programID_ = rhs.programID_;

		return *this;
	}
	
public:

	ShaderManager& operator=(ShaderManager&& rhs) noexcept {
		glDeleteProgram(programID_);
		if (this == &rhs) {
			return *this;
		}

		programID_ = rhs.programID_;
		isReady_ = rhs.isReady_;
		rhs.isReady_ = false;
		rhs.programID_ = 0;
		return *this;
	}

	
}; 

template<typename ...Args>
inline int ShaderManager::LinkShader(GLuint& programm_id, const Args & ...shader_args)
{
	programm_id = glCreateProgram();
	(glAttachShader(programm_id, shader_args), ...);

	glLinkProgram(programm_id);
	GLint program_linked;
	glGetProgramiv(programm_id, GL_LINK_STATUS, &program_linked);
	if (program_linked != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(programm_id, 1024, &log_length, message);
		std::cout << "Error: " << message << '\n';
		return -1;
	}
	this->programID_ = programm_id;

	isReady_ = true;
	return isReady_;
}
#endif // !BounceBall_ShaderManager_HPP