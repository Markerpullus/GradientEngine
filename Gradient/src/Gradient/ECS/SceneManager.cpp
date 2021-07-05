#include "Gradient/ECS/SceneManager.h"

namespace Gradient
{
	std::map<int, Scene*> SceneManager::scenes;

	int SceneManager::topIndex = 0;

	Scene* SceneManager::currentScene;

	Scene& SceneManager::NewScene()
	{
		Scene* scene = new Scene(topIndex);
		scenes.insert(std::pair<int, Scene*>{topIndex, scene});
		topIndex++;
		return *scene;
	}

	void SceneManager::UnloadScene(int index)
	{
		delete scenes.at(index);
		scenes.at(index) = NULL;
	}

	void SceneManager::UnloadAll()
	{
		for (auto it : scenes)
		{
			delete it.second;
		}
	}
}