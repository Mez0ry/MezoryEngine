#ifndef VERTEX_ARRAY_OBJECT_HPP
#define VERTEX_ARRAY_OBJECT_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class VertexBufferObject;


class VertexArrayObject
{
private:
	GLuint vao_id_;
	GLenum type_;
public:
	VertexArrayObject() = default;
	~VertexArrayObject();
/**
* @brief generates Vertex Array and binding it
*/
	void GenAndBindVAO(GLenum type);

/**
* @brief Setting up attribute pointer
*/
	void BindVboToLocation(const GLuint location_index, const GLint size, VertexBufferObject& obj, GLboolean normalized, GLsizei stride, const void* pointer);
/**
* @brief bind a vertex array object
*/
	void BindVertexArray();
/**
* @brief unbind a vertex array object
*/
	void UnBind();
	
private:

};

#endif // !BounceBall_VERTEX_ARRAY_OBJECT_HPP