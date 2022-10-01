#ifndef VERTEX_BUFFER_OBJECT_HPP
#define VERTEX_BUFFER_OBJECT_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class VertexBufferObject
{
private:
	GLuint vbo_id_;
public:
	VertexBufferObject() = default;
	VertexBufferObject(unsigned int size, const void* data);
	~VertexBufferObject();

	void Bind();
	void UnBind();

	GLuint get_id() { return vbo_id_; }
private:
};

#endif // !BounceBall_VERTEX_BUFFER_OBJECT_HPP