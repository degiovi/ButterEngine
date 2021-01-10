#pragma once

#include "ButterEngine/Core/Core.h"

namespace Butter
{
	class Texture
	{
		
	public:
		
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetData(void * in_data, uint32_t in_size) = 0;

		virtual void Bind(uint32_t in_slot = 0) const = 0;
		virtual void BindCompute(uint32_t in_slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(uint32_t in_width, uint32_t in_height);
		static Ref<Texture2D> Create(std::string & in_filePath);
	};
}