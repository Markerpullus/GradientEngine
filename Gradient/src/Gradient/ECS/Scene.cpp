#include "Gradient/ECS/Scene.h"
#include "Gradient/ECS/Actor.h"

namespace Gradient
{
	Scene::Scene(int i)
		: index(i)
	{ }

	Scene::~Scene()
	{
		registry.clear();
	}

	Actor& Scene::CreateActor()
	{
		Actor actor(registry.create(), this);
		return actor;
	}

	void Scene::DestroyActor(Actor& actor)
	{
		registry.destroy(actor.handle);
	}

	void Scene::OnUpdate()
	{
		// Componenet handlers
	}
}