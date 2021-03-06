#pragma once
#include "ButterEngine/Renderer/Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Butter
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader();
		virtual ~OpenGLShader();

		
		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetInt(const std::string & in_name, int in_value) override;
		virtual void SetFloat(const std::string & in_name, float in_value) override;
		virtual void SetFloat2(const std::string & in_name, const glm::vec2 & in_value) override;
		virtual void SetFloat3(const std::string & in_name, const glm::vec3 & in_value) override;
		virtual void SetFloat4(const std::string & in_name, const glm::vec4 & in_value) override;
		virtual void SetMat4(const std::string & in_name, const glm::mat4 & in_value) override;

		virtual void DispatchCompute(uint32_t x, uint32_t y, uint32_t z) override;
	
		virtual const std::string & GetName() const override { return name; }

		virtual void AddShaderSource(const std::string & in_filePath, ShaderType in_shaderType) override;

		void UploadUniformInt(const std::string & name, int value);

		void UploadUniformFloat(const std::string & name, float value);
		void UploadUniformFloat2(const std::string & name, const glm::vec2 & value);
		void UploadUniformFloat3(const std::string & name, const glm::vec3 & value);
		void UploadUniformFloat4(const std::string & name, const glm::vec4 & value);

		void UploadUniformMat3(const std::string & name, const glm::mat3 & matrix);
		void UploadUniformMat4(const std::string & name, const glm::mat4 & matrix);
	

	private:
		std::string ReadFile(const std::string & in_filePath);								// This should not be here, it should be in some generic class which handles file systems/reading/writing
		std::unordered_map<GLenum, std::string> PreProcess(const std::string & src);
		virtual void Compile() override;

	private:
		uint32_t rendererID;
		std::string name;

		std::unordered_map<GLenum, std::string> shaders;
	};
}