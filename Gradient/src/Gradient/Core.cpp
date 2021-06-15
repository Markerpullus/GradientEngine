#include "Core.h"
#include "Gradient/Core/Log.h"
#include "glad/glad.h"

void glClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool glLogCall(const char* function, const char* file, const int line)
{
	while (GLenum error = glGetError())
	{
		GD_CORE_ERROR("OpenGL runtime exception: {0} \n File {1}, line {2} in {3}", error, file, line, function);
		return false;
	}
	return true;
}
