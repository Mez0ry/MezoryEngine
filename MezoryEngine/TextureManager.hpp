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
* @brief  Set the texture wrapping/filtering options (on the currently bound texture object)
*/
	void set_TextureParami(GLenum target, GLenum pname, GLint param);
	/**
	* @brief loads and generates texture
	*/
	void LoadAndGenerate2DTexture(const char* texture_path, int desired_channels);
	void BindTexture(GLenum target);
private:
	int width_;
	int height_;
	int nrChannels_;

};

#endif // !BounceBall_TEXTURE_MANAGER_HPP