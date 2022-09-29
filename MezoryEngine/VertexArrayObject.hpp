#ifndef BounceBall_VERTEX_ARRAY_OBJECT_HPP
#define BounceBall_VERTEX_ARRAY_OBJECT_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class VertexBufferObject;


class VertexArrayObject
{
private:
	GLuint vao_id_;
	GLenum type_;
public:
	VertexArrayObject(GLenum type);
	~VertexArrayObject();

	/**
	* @brief Setting up attribute pointer
	*/
	void BindVboToLocation(const GLuint location_index, const GLint size, VertexBufferObject& obj, GLboolean normalized, GLsizei stride, const void* pointer);
	
	void BindVertexArray();

	void unbind();
	
private:

};

#endif // !BounceBall_VERTEX_ARRAY_OBJECT_HPP