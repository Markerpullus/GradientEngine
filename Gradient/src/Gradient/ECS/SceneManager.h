#pragma once

#include "Gradient/Core.h"
#include "Gradient/ECS/Scene.h"

#include <map>

namespace Gradient
{
	class GD_API SceneManager
	{
	private:
		static std::map<int, Scene*> scenes;

		static int topIndex;

		static Scene* currentScene;

	public:
		static Scene& NewScene();

		static void LoadScene(int index);

		static void LoadSceneAsync(int index);

		static void UnloadScene(int index);

		static void UnloadAll();
	};
}
