#include <btrpch.h>
#include "OpenGLTexture2D.h"
#include "ButterEngine/Renderer/Texture.h"

#include <stb_image.h>

namespace Butter
{
	OpenGLTexture2D::OpenGLTexture2D(uint32_t in_width, uint32_t in_height)
		: width(in_width), height(in_height)
	{
		internalFormat = GL_RGBA8;
		dataFormat = GL_RGBA;

		glCreateTextures(GL_TEXTURE_2D, 1, &rendererID);
		glTextureStorage2D(rendererID, 1, internalFormat, width, height);
		
		glTextureParameteri(rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(rendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(rendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::OpenGLTexture2D(const std::string & in_filePath)
		: filePath(in_filePath)
	{
		int width, height, channels;

		stbi_set_flip_vertically_on_load(1);
		stbi_uc * data = nullptr;
		{
			data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
		}

		BTR_CORE_ASSERT(data, "Failed to load image!");

		this->width = width;
		this->height = height;

		GLenum internalFormat = 0, dataFormat = 0;

		if (channels == 4)
		{
			internalFormat = GL_RGBA32F;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3)
		{
			internalFormat = GL_RGB32F;
			dataFormat = GL_RGB;
		}
		
		this->internalFormat = internalFormat;
		this->dataFormat = dataFormat;

		BTR_CORE_ASSERT(internalFormat & dataFormat, "Format not supported!");

		glCreateTextures(GL_TEXTURE_2D, 1, &rendererID);
		glTextureStorage2D(rendererID, 1, internalFormat, width, height);

		glTextureParameteri(rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(rendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(rendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//glTextureSubImage2D(rendererID, 0, 0, 0, this->width, this->height, dataFormat, GL_UNSIGNED_BYTE, data);
		glTextureSubImage2D(rendererID, 0, 0, 0, this->width, this->height, dataFormat, GL_UNSIGNED_BYTE, data);
		//glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, this->width, this->height, 0, dataFormat, GL_FLOAT, data);
		
		stbi_image_free(data);

	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &rendererID);
	}


	void OpenGLTexture2D::SetData(void * in_data, uint32_t in_size)
	{
		uint32_t bpp = dataFormat == GL_RGBA ? 4 : 3;	// bytes per pixel
		BTR_CORE_ASSERT(size == width * height * bpp, "Data must be entire texture!");

		//glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, this->width, this->height, 0, dataFormat, GL_FLOAT, in_data);

		glTextureSubImage2D(rendererID, 0, 0, 0, width, height, dataFormat, GL_UNSIGNED_BYTE, in_data);
	}

	void OpenGLTexture2D::Bind(uint32_t in_slot) const
	{
		glBindTextureUnit(in_slot, rendererID);
	}

	void OpenGLTexture2D::BindCompute(uint32_t in_slot) const
	{
		glBindImageTexture(0, rendererID, 0, GL_FALSE, 0, GL_WRITE_ONLY, internalFormat);

	}


}