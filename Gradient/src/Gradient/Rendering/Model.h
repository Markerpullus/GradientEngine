#pragma once

#include "Gradient/Core.h"

namespace Gradient
{
	class GD_API Model
	{
	private:
		char* filePath;

		void LoadModel(char* path);

	public:
		Model(char* path);

		void Draw();
	};
}
