#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "boost/bind.hpp"
#include "Gradient/Core/Application.h"
#include "Gradient/Core/Log.h"
#include "Gradient/Rendering/Renderer.h"
#include "Gradient/Rendering/Camera/OrthographicCamera.h"
#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

namespace Gradient
{
	Application* Application::self;
	Application::Application()
	{
		running = true;
		window = std::make_unique<Window>(Window());
		scopeStack = std::make_unique<ScopeStack>(ScopeStack());

		window->SetMainEventCallBack(boost::bind(&Application::MainEventHandler, this, _1));
		self = this;
	}

	Application::~Application()
	{
		
	}

	void Application::MainEventHandler(Event& e)
	{
		switch (e.name)
		{
		case EventName::WindowClose:
			running = false;
			break;
		case EventName::KeyDown:
			GD_CORE_INFO("Key Down: {}", dynamic_cast<KeyDownEvent&>(e).ToChar());
			break;
		case EventName::KeyUp:
			GD_CORE_INFO("Key Up: {}", dynamic_cast<KeyUpEvent&>(e).ToChar());
			break;
		case EventName::KeyRepeat:
			GD_CORE_INFO("Key Repeat");
			break;
		case EventName::KeyTyped:
			GD_CORE_INFO("Key Typed: {}", dynamic_cast<KeyTypedEvent&>(e).ToChar());
			break;
		}
	}

	void Application::Run()
	{
		// 2D Test
		/*
		Vector3 positions[] = { Vector3(0.5f, 0.5f, 0.0f), Vector3(0.5f, -0.5f, 0.0f), Vector3(-0.5f, -0.5f, 0.0f), Vector3(-0.5f, 0.5f, 0.0f) };
		Vector2 texCoords[] = { Vector2(1.0f, 1.0f), Vector2(1.0f, 0.0f), Vector2(0.0f, 0.0f), Vector2(0.0f, 1.0f) };
		Vertex2D verticesArray[4];
		for (int i = 0; i < 4; i++)
		{
			verticesArray[i] = Vertex2D{positions[i], texCoords[i]};
		}
		std::vector<Vertex2D> vertices(verticesArray, verticesArray + 4);
		std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
		Texture texture = Texture(100, 100, Vector3(1.0f, 0.0f, 1.0f), TextureType::Default);
		Mesh2D mesh(vertices, indices, texture);
		Model2D model(std::vector<Mesh2D>{mesh}, glm::rotate(Matrix4(1.0f), glm::radians(45.0f), Vector3(0.0f, 1.0f, 0.0f)));
		Shader shader2D("../Gradient/src/Gradient/Shaders/2D.glsl");
		//OrthographicCamera cam(Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f), 2.0f, 2.0f, 1.0f, 2.0f);
		PerspectiveCamera cam(Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f), 2.0f, 2.0f, 90.0f, 0.01f, 2.0f);*/
		

		// 3D Test
		Vector3 positions[] = { Vector3(-0.5f, -0.5f, -0.5f), Vector3(0.5f, -0.5f, -0.5f), Vector3(0.5f, 0.5f, -0.5f), Vector3(0.5f, 0.5f, -0.5f),
		Vector3(-0.5f, 0.5f, -0.5f), Vector3(-0.5f, -0.5f, -0.5f) };
		Vector3 normals[] = { Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f),
		Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f) };
		Vector2 texCoords[] = { Vector2(0, 0), Vector2(1, 0), Vector2(1, 1), Vector2(1, 1), Vector2(0, 1), Vector2(0, 0) };
		Vertex3D verticesArray[6];
		for (int i = 0; i < 6; i++)
		{
			verticesArray[i] = Vertex3D{ positions[i], normals[i], texCoords[i] };
		}
		std::vector<Vertex3D> vertices(verticesArray, verticesArray + 6);
		std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5 };
		Texture diffuse(100, 100, Vector3(1.0f, 0.5f, 0.31f), TextureType::Default);
		Texture specular(100, 100, Vector3(1.0f, 1.0f, 1.0f), TextureType::Default);
		float shininess = 32.0f;
		Material material = { diffuse, specular, shininess };
		Mesh3D mesh(vertices, indices, material);
		Model3D model(std::vector<Mesh3D>{mesh}, glm::rotate(Matrix4(1.0f), glm::radians(30.0f), Vector3(0.0f, 1.0f, 0.0f)));
		Shader shader3D("../Gradient/src/Gradient/Shaders/Phong.glsl");
		PerspectiveCamera cam(Vector3(0.0f, 0.0f, 2.0f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f), 2.0f, 2.0f, 90.0f, 0.01f, 100.0f);
		std::vector<Light*> lights = { &PointLight(Vector3(0.15f, 0.15f, 0.15f), Vector3(0.5f, 0.5f, 0.5f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.5f, 1.0f, 2.0f)) };
		Renderer renderer(cam);

		while (running)
		{
			renderer.SetClearColor(Vector3(0.0f, 0.0f, 0.0f));
			renderer.BeginFrame();

			renderer.DrawModel(model, shader3D, lights);

			renderer.EndFrame();
		}
	}
}