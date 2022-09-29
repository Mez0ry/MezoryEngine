#ifndef BounceBall_VERTEX_BUFFER_OBJECT_HPP
#define BounceBall_VERTEX_BUFFER_OBJECT_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class VertexBufferObject
{
private:
	GLuint vbo_id_;
public:
	VertexBufferObject(unsigned int size, const void* data);
	~VertexBufferObject();

	void bind();
	void unBind();

	GLuint get_id() { return vbo_id_; }
private:
};

#endif // !BounceBall_VERTEX_BUFFER_OBJECT_HPP