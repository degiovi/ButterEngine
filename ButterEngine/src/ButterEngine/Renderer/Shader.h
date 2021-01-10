#pragma once
#include <string>

#include <glm/glm.hpp>

namespace Butter
{

	enum class ShaderType
	{
		None = 0, Vertex = 1, Fragment = 2, Compute = 3
	};

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetInt(const std::string & in_name, int in_value) = 0;
		virtual void SetFloat(const std::string & in_name, float in_value) = 0;
		virtual void SetFloat2(const std::string & in_name, const glm::vec2 & in_value) = 0;
		virtual void SetFloat3(const std::string & in_name, const glm::vec3 & in_value) = 0;
		virtual void SetFloat4(const std::string & in_name, const glm::vec4 & in_value) = 0;
		virtual void SetMat4(const std::string & in_name, const glm::mat4 & in_value) = 0;

		virtual void DispatchCompute(uint32_t x, uint32_t y, uint32_t z) = 0;

		virtual const std::string & GetName() const = 0;

		static Ref<Shader> Create();

		virtual void AddShaderSource(const std::string & in_filePath, ShaderType in_shaderType) = 0;
		virtual void Compile() = 0;

	private:
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