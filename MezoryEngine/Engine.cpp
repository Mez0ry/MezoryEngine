#include "Engine.hpp"
GLfloat points[] = {
0.5f, 0.5f, 0.0f,
-0.5f, 0.5f, 0.0f,
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f
};

GLfloat texturePoints[]{
	1.0f, 0.0f,
	1.0f, 0.8f,
	0.0f, 0.0f,
	0.0f, 1.0f
};

GLfloat color[] = {
	1.0f, 0.0, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f
};


const char* vertex_shader = {
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

const char* fragment_shader = {
	"#version 460\n"
	"out vec4 FragColor;"

	"in vec3 ourColor;"
	"in vec2 TexCoord;"

	"uniform sampler2D ourTexture;"

	"void main(){ "
	"  FragColor = texture(ourTexture, TexCoord);"
	"}"
};

Engine::Engine() : engineLoop_(true)
{
	oglContext_.Initialize();

	glClearColor(0.0f, 0.f, 0.f, 1.f);
	textureManager_.setup();

	textureManager_.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	textureManager_.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	textureManager_.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	textureManager_.set_TextureParami(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	textureManager_.LoadAndGenerate2DTexture("..\\MezoryEngine\\ant.jpg", 0);

	GLuint vs, fs, pid;
	shaderManager_.CreateShader(vertex_shader, GL_VERTEX_SHADER, vs);
	shaderManager_.CreateShader(fragment_shader, GL_FRAGMENT_SHADER, fs);
	shaderManager_.LinkShader(pid, vs, fs);
	
}

Engine::~Engine()
{

}

void Engine::Play()
{
	VertexBufferObject points_vbo(4 * 3 * sizeof(float), points);
	VertexBufferObject color_vbo(4 * 4 * sizeof(float), color);
	VertexBufferObject texture_vbo(4 * 2 * sizeof(float), texturePoints);

	vertexArrayobject_.GenAndBindVAO(GL_FLOAT);

	vertexArrayobject_.BindVboToLocation(0, 4, points_vbo, GL_FALSE, 0, nullptr);
	vertexArrayobject_.BindVboToLocation(1, 4, color_vbo, GL_FALSE, 0, nullptr);
	vertexArrayobject_.BindVboToLocation(2, 2, texture_vbo, GL_FALSE, 0, nullptr);

	textureManager_.BindTexture(GL_TEXTURE_2D);

	while (engineLoop_ && !glfwWindowShouldClose(oglContext_.get_window())) {

		EventHandler();
		Update();
		Draw();
	}

}

void Engine::EventHandler()
{
	if (InputHandler::EnginePollEvent(oglContext_.get_window(), &ev_))
	{
		std::cout << "Mouse x: " << ev_.mouse_pos.x << "Mouse y: " << ev_.mouse_pos.y;
		switch (ev_.state)
		{
		case GLFW_PRESS: {

			switch (ev_.key) {
			case GLFW_KEY_Z: {

				break;
			}
			case GLFW_KEY_ESCAPE: {
				engineLoop_ = false;
				glfwSetWindowShouldClose(oglContext_.get_window(), GL_TRUE);
				break;
			}
			} // !switch ev.key
			break;
		}// !GLFW_PRESS

		} // !switch ev.state
	}
}

void Engine::Update()
{

}

void Engine::Draw()
{
	glClearColor(1.0f, 1.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	shaderManager_.UseProgram();

	vertexArrayobject_.BindVertexArray();

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glfwSwapBuffers(oglContext_.get_window());
}
