#include "btrpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "ButterEngine/Platform/OpenGL/OpenGLShader.h"

namespace Butter
{
	Ref<Shader> Butter::Shader::Create(const std::string & in_filePath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		BTR_CORE_ASSERT(false, "Selected RendererAPI is not supported.");
			case RendererAPI::API::OpenGL:		return CreateRef<OpenGLShader>(in_filePath);
		}

		BTR_CORE_ASSERT(false, "Unknown Renderer API, could not create shader.");

		return nullptr;
	}
	
	void ShaderLibrary::Add(const std::string & in_name, const Ref<Shader> & in_shader)
	{
		BTR_CORE_ASSERT(!Exists(in_name), "Shader already exists.");
		shaders[in_name] = in_shader;
	}

	void ShaderLibrary::Add(const Ref<Shader> & in_shader)
	{
		auto & name = in_shader->GetName();
		Add(name, in_shader);
	}

	Ref<Shader> ShaderLibrary::Load(const std::string & in_filePath)
	{
		auto shader = Shader::Create(in_filePath);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string & in_name, const std::string & in_filePath)
	{
		auto shader = Shader::Create(in_filePath);
		Add(in_name, shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string & in_name)
	{
		BTR_CORE_ASSERT(Exists(in_name), "Shader does not exist!");
		return shaders[in_name];
	}

	bool ShaderLibrary::Exists(const std::string & in_name) const
	{
		return shaders.find(in_name) != shaders.end();
	}
}
