#pragma once
#include <string>

#include <glm/glm.hpp>

namespace Butter
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetInt(const std::string & in_name, int in_value) = 0;
		virtual void SetFloat3(const std::string & in_name, const glm::vec3 & in_value) = 0;
		virtual void SetFloat4(const std::string & in_name, const glm::vec4 & in_value) = 0;
		virtual void SetMat4(const std::string & in_name, const glm::mat4 & in_value) = 0;

		virtual const std::string & GetName() const = 0;

		static Ref<Shader> Create(const std::string & in_filePath);

	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string & in_name, const Ref<Shader> & in_shader);
		void Add(const Ref<Shader> & in_shader);

		Ref<Shader> Load(const std::string & in_filePath);
		Ref<Shader> Load(const std::string & in_name, const std::string & in_filePath);
	
		Ref<Shader> Get(const std::string & name);

		bool Exists(const std::string & name) const;

	private:
		std::unordered_map<std::string, Ref<Shader>> shaders;
	};
}