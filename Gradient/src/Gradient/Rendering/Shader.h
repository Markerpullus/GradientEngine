#pragma once

#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Material.h"

#include <vector>
#include <unordered_map>

namespace Gradient
{
	class Shader
	{
	private:
		unsigned int programID;
		unsigned int vsid;
		unsigned int fsid;
		std::unordered_map<std::string, int> uniformLocationCache;

		void ReadShader(const std::string& file, std::string& vertexShader, std::string& fragmentShader);

		unsigned int CompileShader(unsigned int type, const std::string& source);

	public:
		Shader(const std::string& file);

		~Shader();

		void Bind();

		void Unbind();

		void SetUniform1i(const char* name, int val1);

		void SetUniform1f(const char* name, float val1);

		void SetUniform3f(const char* name, float val1, float val2, float val3);

		void SetUniform3f(const char* name, glm::vec3 vals);

		void SetUniform4f(const char* name, float val1, float val2, float val3, float val4);

		void SetUniform4f(const char* name, glm::vec4 vals);

		void SetUniformMat4f(const char* name, const glm::mat4& mat);

		void SetUniformMaterial(char* name, const Material& mat);

		void SetUniformLight(char* name, const Light& light);

		unsigned int GetUniformLocation(const std::string& name);
	};
}
