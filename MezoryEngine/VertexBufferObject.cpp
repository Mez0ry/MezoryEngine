#include "VertexBufferObject.hpp"

VertexBufferObject::VertexBufferObject(unsigned int size, const void* data) : vbo_id_(NULL)
{
	glGenBuffers(1, &vbo_id_);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &vbo_id_);
}

void VertexBufferObject::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
}

void VertexBufferObject::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
 
}
