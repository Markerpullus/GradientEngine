#include "Gradient/Core/Log.h"
#include "Gradient/Rendering/Shader.h"
#include "glad/glad.h"

#include <fstream>

namespace Gradient
{

	void Shader::ReadShader(const std::string& file, std::string& vertexShader, std::string& fragmentShader)
	{
		GD_CORE_INFO(file);
		std::ifstream stream(file);
		ASSERT(stream.good());
		enum class shaderType
		{
			None = -1, Vertex = 0, Fragment = 1
		};
		std::string line;
		shaderType type;
		while (getline(stream, line))
		{
			GD_CORE_INFO("{}", line);
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = shaderType::Vertex;
				else if (line.find("fragment") != std::string::npos)
					type = shaderType::Fragment;
			}
			else {
				(type == shaderType::Vertex) ? vertexShader.append(line + '\n') :
					fragmentShader.append(line + '\n');
			}
		}
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			GD_CORE_ERROR("Failed to compile {} shader: \n{}", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"), message);
			glDeleteShader(id);

			return 0;
		}

		return id;
	}

	Shader::Shader(const std::string& file)
	{
		std::string vertexShader, fragmentShader;
		ReadShader(file, vertexShader, fragmentShader);
		id = glCreateProgram();
		vsid = CompileShader(GL_VERTEX_SHADER, vertexShader);
		fsid = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(id, vsid);
		glAttachShader(id, fsid);
		glLinkProgram(id);
		glValidateProgram(id);

		glDeleteShader(vsid);
		glDeleteShader(fsid);
	}

	Shader::~Shader()
	{
		glUseProgram(0);
		glDeleteProgram(id);
	}

	void Shader::Bind()
	{
		glUseProgram(id);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetUniform1i(const char* name, int val1)
	{
		glUniform1i(GetUniformLocation(name), val1);
	}

	void Shader::SetUniform1f(const char* name, float val1)
	{
		glUniform1f(GetUniformLocation(name), val1);
	}

	void Shader::SetUniform3f(const char* name, float val1, float val2, float val3)
	{
		glUniform3f(GetUniformLocation(name), val1, val2, val3);
	}

	void Shader::SetUniform3f(const char* name, glm::vec3 vals)
	{
		glUniform3fv(GetUniformLocation(name), 1, &vals[0]);
	}

	void Shader::SetUniform4f(const char* name, float val1, float val2, float val3, float val4)
	{
		glUniform4f(GetUniformLocation(name), val1, val2, val3, val4);
	}

	void Shader::SetUniform4f(const char* name, glm::vec4 vals)
	{
		glUniform4fv(GetUniformLocation(name), 1, &vals[0]);
	}

	void Shader::SetUniformMat4f(const char* name, const glm::mat4& mat)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
	}

	void Shader::SetUniformMaterial(char* name, const Material& mat)
	{
		SetUniform3f(strcat(name, ".ambient"), mat.Ambient);
		SetUniform3f(strcat(name, ".diffuse"), mat.Diffuse);
		SetUniform3f(strcat(name, ".specular"), mat.Specular);
		SetUniform1f(strcat(name, ".shininess"), mat.Shininess);
	}

	void Shader::SetUniformLight(char* name, const Light& light)
	{
		SetUniform3f(strcat(name, ".position"), light.Position);
		SetUniform3f(strcat(name, ".ambient"), light.Ambient);
		SetUniform3f(strcat(name, ".diffuse"), light.Diffuse);
		SetUniform3f(strcat(name, ".specular"), light.Specular);
	}

	unsigned int Shader::GetUniformLocation(const std::string& name)
	{
		if (uniformLocationCache.find(name) != uniformLocationCache.end())
			return uniformLocationCache[name];

		int location = glGetUniformLocation(id, name.c_str());
		ASSERT(location != -1);
		uniformLocationCache.insert({ name, location });
		return location;
	}
}