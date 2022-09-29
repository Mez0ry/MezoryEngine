#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include <iostream>
class TextureManager
{
private:
	GLuint texture_id_;
public:
	TextureManager();
	~TextureManager();
/**
* @brief  set the texture wrapping/filtering options (on the currently bound texture object)
*/
	void set_TextureParams(GLenum target, GLenum pname, GLint param);

	void LoadAndGenerateTexture(const char* texture_path, int& width, int& height, int& nrChannels, int desired_channels);
	void BindTexture(GLenum target);
private:
 
};

#endif // !BounceBall_TEXTURE_MANAGER_HPP