#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"


VertexArrayObject::VertexArrayObject(GLenum type)
{
	this->type_ = type;
	glGenVertexArrays(1, &vao_id_);
	BindVertexArray();
}


VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &vao_id_);
}

void VertexArrayObject::BindVboToLocation(const GLuint location_index, const GLint size, VertexBufferObject& obj, GLboolean normalized, GLsizei stride, const void* pointer)
{
	glEnableVertexAttribArray(location_index);
	glBindBuffer(GL_ARRAY_BUFFER, obj.get_id());
	glVertexAttribPointer(location_index, size, type_, normalized, stride, pointer);
}

void VertexArrayObject::BindVertexArray()
{
	glBindVertexArray(vao_id_);
}

void VertexArrayObject::UnBind()
{
	glBindVertexArray(0);
}
