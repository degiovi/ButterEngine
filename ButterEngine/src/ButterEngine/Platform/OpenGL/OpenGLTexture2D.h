#pragma once
#include "ButterEngine/Renderer/Texture.h"

#include <glad/glad.h>

namespace Butter
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		
		OpenGLTexture2D(uint32_t in_width, uint32_t in_height);
		OpenGLTexture2D(const std::string & in_filePath);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidth() const override { return width; }
		virtual uint32_t GetHeight() const override { return height; }

		virtual void SetData(void * in_data, uint32_t in_size) override;
		
		virtual void Bind(uint32_t in_slot = 0) const override;
		virtual void BindCompute(uint32_t in_slot = 0) const override;

	private:

		uint32_t width;
		uint32_t height;

		std::string filePath;

		uint32_t rendererID;

		GLenum internalFormat, dataFormat;
	};
}