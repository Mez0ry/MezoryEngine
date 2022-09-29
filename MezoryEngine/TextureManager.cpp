#include "TextureManager.hpp"

TextureManager::TextureManager()
{
	glGenTextures(1, &texture_id_);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_id_);
}

TextureManager::~TextureManager()
{
}

void TextureManager::set_TextureParams(GLenum target, GLenum pname, GLint param)
{
	glTexParameteri(texture_id_, pname, param);
}

void TextureManager::LoadAndGenerateTexture(const char* texture_path, int& width, int& height, int& nrChannels, int desired_channels)
{
	unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << '\n';
		if (stbi_failure_reason())
			std::cout << stbi_failure_reason();
	}

	stbi_image_free(data);
}

void TextureManager::BindTexture(GLenum target)
{
	glBindTexture(target, texture_id_);
}

 
