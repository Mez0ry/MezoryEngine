#include "ShaderManager.hpp"

ShaderManager::ShaderManager(const char* vs, const char* fs)
{
	GLuint vs_id;
	CreateShader(vs, GL_VERTEX_SHADER, vs_id);

	GLuint fs_id;
	CreateShader(fs, GL_FRAGMENT_SHADER, fs_id);

	GLuint programm_id;
	LinkShader(programm_id, vs_id, fs_id);

	glDeleteShader(vs_id);
	glDeleteShader(fs_id);
	 
}

ShaderManager::~ShaderManager()
{
	glDeleteProgram(programID_);
}

int ShaderManager::CreateShader(const char* source, const GLenum& shader_type, GLuint& id)
{
	isReady_ = false;
	id = glad_glCreateShader(shader_type);
	glad_glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	GLint compile_status = 0;
	glGetProgramiv(id, GL_COMPILE_STATUS, &compile_status);
	if (compile_status != GL_TRUE) {
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(id, 1024, &log_length, message);
		return -1;
	}
	
	return 1;
}

void ShaderManager::UseProgram()
{
	if (!isReady_) return;

	glUseProgram(programID_);
}
