#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "boost/bind.hpp"
#include "Gradient/Core/Application.h"
#include "Gradient/Core/Log.h"
#include "Gradient/Rendering/Model/Mesh2D.h"

namespace Gradient
{
	Application* Application::self;
	Application::Application()
	{
		window = std::make_unique<Window>(Window());
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
		Vector3 positions[] = { Vector3(0.5f, 0.5f, 0.0f), Vector3(0.5f, -0.5f, 0.0f), Vector3(-0.5f, -0.5f, 0.0f), Vector3(-0.5f, 0.5f, 0.0f) };
		Vector2 texCoords[] = { Vector2(1.0f, 1.0f), Vector2(1.0f, 0.0f), Vector2(0.0f, 0.0f), Vector2(0.0f, 1.0f) };
		Vertex2D verticesArray[4];
		for (int i = 0; i < 4; i++)
		{
			verticesArray[i] = Vertex2D{positions[i], texCoords[i]};
		}
		std::vector<Vertex2D> vertices(verticesArray, verticesArray + 4);
		std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
		std::vector<Texture> textures = { Texture("glizzy.png", TextureType::Default) };
		Mesh2D mesh(vertices, indices, textures);
		Shader shader("../Gradient/src/Gradient/Shaders/2D.glsl");

		while (!glfwWindowShouldClose(window->GetGLFWwindow()))
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			mesh.Draw(shader);

			glfwSwapBuffers(window->GetGLFWwindow());
			glfwPollEvents();
		}
	}
}