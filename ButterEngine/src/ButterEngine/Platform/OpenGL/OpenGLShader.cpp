#include "btrpch.h"
#include "OpenGLShader.h"

#include <fstream>
#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace Butter
{
	static GLenum ShaderTypeFromString(const std::string & type)
	{
		if (type == "compute")
			return GL_COMPUTE_SHADER;
		else if (type == "fragment")
			return GL_FRAGMENT_SHADER;
		else if (type == "vertex")
			return GL_VERTEX_SHADER;

		BTR_CORE_ASSERT(false, "Unknown shader type.");

		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string & in_filePath)
	{
		std::string shaderSrc = ReadFile(in_filePath);
		auto shaderSrcs = PreProcess(shaderSrc);
		Compile(shaderSrcs);

		// Extract name from filepath
		auto lastSlash = in_filePath.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		auto lastDot = in_filePath.rfind('.');
		auto count = lastDot == std::string::npos ? in_filePath.size() - lastSlash : lastDot - lastSlash;
		name = in_filePath.substr(lastSlash, count);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(rendererID);
	}

	std::string OpenGLShader::ReadFile(const std::string & in_filePath)
	{
		std::string result;
		std::ifstream stream(in_filePath, std::ios::in, std::ios::binary);

		if (stream)
		{
			stream.seekg(0, std::ios::end);
			result.resize(stream.tellg());
			stream.seekg(0, std::ios::beg);
			stream.read(&result[0], result.size());
			stream.close();
		}
		else
		{
			BTR_CORE_ASSERT("Could not read file '{0}'", in_filePath);
		}

		return result;
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string & src)
	{
		std::unordered_map<GLenum, std::string> shaderSrcs;

		const char * typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = src.find(typeToken, 0);

		while (pos != std::string::npos)
		{
			size_t eol = src.find_first_of("\r\n", pos);
			BTR_CORE_ASSERT(eol != std::string::npos, "Syntax error");

			size_t begin = pos + typeTokenLength + 1;
			std::string type = src.substr(begin, eol - begin);

			GLenum shaderType = ShaderTypeFromString(type);
			BTR_CORE_ASSERT(shaderType, "Invalid shader type specified.");

			size_t nextLinePos = src.find_first_not_of("\r\n", eol);
			pos = src.find((typeToken, nextLinePos));

			shaderSrcs[shaderType] = src.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? src.size() - 1 : nextLinePos));
			
			return shaderSrcs;
		}

	}

	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string> & shaderSrcs)
	{
		GLuint program = glCreateProgram();

		std::vector<GLenum> shaderIDs(shaderSrcs.size());

		for (auto & [key,value] : shaderSrcs)
		{
			GLenum type = key;
			const std::string & src = value;

			GLuint shader = glCreateShader(type);

			const GLchar * shaderSrc = src.c_str();
			glShaderSource(shader, 1, &shaderSrc, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;

			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				BTR_CORE_ERROR("{0}", infoLog.data());
				BTR_CORE_ASSERT(false, "Error in shader compilation!");
				break;
			}

			glAttachShader(program, shader);
			shaderIDs.push_back(shader);
		}

		glLinkProgram(program);

		GLint isProgramLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isProgramLinked);

	
		if (isProgramLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);

			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			for (auto id : shaderIDs)
				glDeleteShader(id);

			BTR_CORE_ERROR("{0}", infoLog.data());
			BTR_CORE_ASSERT(false, "Error in linking shader to program!");
			return;
		}

		for (auto id : shaderIDs)
		{
			glDetachShader(program, id);
		}
		
		rendererID = program;
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(rendererID);
	}
	
	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const std::string & in_name, int in_value)
	{
		UploadUniformInt(in_name, in_value);
	}

	void OpenGLShader::SetFloat3(const std::string & in_name, const glm::vec3 & in_value)
	{
		UploadUniformFloat3(in_name, in_value);
	}

	void OpenGLShader::SetFloat4(const std::string & in_name, const glm::vec4 & in_value)
	{
		UploadUniformFloat4(in_name, in_value);
	}

	void OpenGLShader::SetMat4(const std::string & in_name, const glm::mat4 & in_value)
	{
		UploadUniformMat4(in_name, in_value);
	}

	void OpenGLShader::UploadUniformInt(const std::string & in_name, int in_value)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniform1f(location, in_value);
	}

	void OpenGLShader::UploadUniformFloat(const std::string & in_name, float in_value)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniform1f(location, in_value);
	}

	void OpenGLShader::UploadUniformFloat2(const std::string & in_name, const glm::vec2 & in_value)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniform2f(location, in_value.x, in_value.y);
	}

	void OpenGLShader::UploadUniformFloat3(const std::string & in_name, const glm::vec3 & in_value)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniform3f(location, in_value.x, in_value.y, in_value.z);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string & in_name, const glm::vec4 & in_value)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniform4f(location, in_value.x, in_value.y, in_value.z, in_value.w);
	}

	void OpenGLShader::UploadUniformMat3(const std::string & in_name, const glm::mat3 & in_matrix)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(in_matrix));
	}

	void OpenGLShader::UploadUniformMat4(const std::string & in_name, const glm::mat4 & in_matrix)
	{
		GLint location = glGetUniformLocation(rendererID, in_name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(in_matrix));
	}

}


