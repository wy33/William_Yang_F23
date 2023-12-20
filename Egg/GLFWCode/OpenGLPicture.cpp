#include "pch.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../stbi/stb_image.h"

#include "OpenGLPicture.h"
#include "../Utilities.h"

namespace egg
{
	OpenGLPicture::OpenGLPicture(const std::string& fileName)
	{
		//unsigned int texture;
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(fileName.c_str(), &mWidth, &mHeight, &mChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			EGG_ERROR("Failed to load a picture from the file!");
		}
		stbi_image_free(data);

	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mTexture);
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}

	int OpenGLPicture::GetWidth() const
	{
		return mWidth;
	}

	int OpenGLPicture::GetHeight() const
	{
		return mHeight;
	}
}