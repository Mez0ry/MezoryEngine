#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "OpenglContext.hpp"
#include "InputHandler.hpp"
#include "ShaderManager.hpp"
#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"
#include "TextureManager.hpp"
#include "SceneStateMachine.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Engine
{
private:
	InputHandler::EngineEvent ev_;
	bool engineLoop_ = false;
	OpenglContext oglContext_;
	float timer_ = 0;
public:
	Engine();
	~Engine();
	
	void Play();
private:
	SceneStateMachine sceneStateMachine_;
private:
	ShaderManager shaderManager_;
	TextureManager textureManager_;
	VertexArrayObject vertexArrayobject_;
private:
	void EventHandler();
	void Update();
	void Draw();
};

#endif // !ENGINE_HPP