#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "OpenglContext.hpp"
#include "ShaderManager.hpp"
#include "stb_image.h"
#include "VertexBufferObject.hpp"
#include "VertexArrayObject.hpp"
#include "TextureManager.hpp"
#include "InputHandler.hpp"

GLfloat points[] = {
	0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f};

GLfloat texturePoints[]{
	1.0f, 0.0f,
	1.0f, 0.8f,
	0.0f, 0.0f,
	0.0f, 1.0f};

GLfloat color[] = {
	1.0f, 0.0, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f};

const char *vertex_shader = {
	"#version 460\n"
	"layout(location = 0) in vec3 vertex_position;"
	"layout(location = 1) in vec3 color;"
	"layout(location = 2) in vec2 texture_coords;"

	"out vec3 ourColor;"
	"out vec2 TexCoord;"

	"void main(){"
	" gl_Position = vec4(vertex_position, 1.0);"
	" ourColor = color;"
	" TexCoord = texture_coords;"
	"}"
};

const char *fragment_shader = {
	"#version 460\n"
	"out vec4 FragColor;"

	"in vec3 ourColor;"
	"in vec2 TexCoord;"

	"uniform sampler2D ourTexture;"

	"void main(){ "
	"  FragColor = texture(ourTexture, TexCoord);"
	"}"
};

int main() {
	OpenglContext glContext;
	glContext.Initialize();

	glClearColor(0.0f, 0.f, 0.f, 1.f);
	ShaderManager shader_manager;

	TextureManager antTexture;

	antTexture.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	antTexture.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	antTexture.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	antTexture.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	antTexture.LoadAndGenerate2DTexture("..\\MezoryEngine\\ant.jpg", 0);

	GLuint vs, fs, pid;
	shader_manager.CreateShader(vertex_shader, GL_VERTEX_SHADER, vs);
	shader_manager.CreateShader(fragment_shader, GL_FRAGMENT_SHADER, fs);
	shader_manager.LinkShader(pid, vs, fs);

	VertexBufferObject points_vbo(4 * 3 * sizeof(float), points);

	VertexBufferObject color_vbo(4 * 4 * sizeof(float), color);

	VertexBufferObject texture_vbo(4 * 2 * sizeof(float), texturePoints);

	VertexArrayObject vao(GL_FLOAT);

	vao.BindVboToLocation(0, 4, points_vbo, GL_FALSE, 0, nullptr);

	vao.BindVboToLocation(1, 4, color_vbo, GL_FALSE, 0, nullptr);

	vao.BindVboToLocation(2, 2, texture_vbo, GL_FALSE, 0, nullptr);

	antTexture.BindTexture(GL_TEXTURE_2D);

	while (!glfwWindowShouldClose(glContext.get_window())) {
		glClearColor(1.0f, 1.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		InputHandler::EngineEvent ev;
		if (InputHandler::EnginePollEvent(glContext.get_window(), &ev))
		{
			std::cout << "Mouse x: " << ev.mouse_pos.x << "Mouse y: " << ev.mouse_pos.y;
			switch (ev.state)
			{
			case GLFW_PRESS: {
				switch (ev.key) {
				case GLFW_KEY_Z: {
					 
					break;
				}
				case GLFW_KEY_ESCAPE: {
					glfwSetWindowShouldClose(glContext.get_window(), GL_TRUE);
					break;
				}
				} // !switch ev.key
				break;
			}
			} // !switch ev.state
		}
		 

		shader_manager.UseProgram();

		vao.BindVertexArray();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glfwSwapBuffers(glContext.get_window());
	}

	return 0;
}

 