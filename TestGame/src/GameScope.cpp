#include "GameScope.h"

GameScope::GameScope()
	: Scope("Game")
{

}

void GameScope::OnAttach()
{
	// I know bro, the code is ugly af
	/*
	Vector3 positions[] = { Vector3(-0.5f, -0.5f, -0.5f), Vector3(0.5f, -0.5f, -0.5f), Vector3(0.5f, 0.5f, -0.5f), Vector3(0.5f, 0.5f, -0.5f),
		Vector3(-0.5f, 0.5f, -0.5f), Vector3(-0.5f, -0.5f, -0.5f) };
	Vector3 normals[] = { Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f),
	Vector3(0.0f,  0.0f, 1.0f), Vector3(0.0f,  0.0f, 1.0f) };
	Vector2 texCoords[] = { Vector2(0, 0), Vector2(1, 0), Vector2(1, 1), Vector2(1, 1), Vector2(0, 1), Vector2(0, 0) };
	Gradient::Vertex3D verticesArray[6];
	for (int i = 0; i < 6; i++)
	{
		verticesArray[i] = Gradient::Vertex3D{ positions[i], normals[i], texCoords[i] };
	}
	std::vector<Gradient::Vertex3D> vertices(verticesArray, verticesArray + 6);
	std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5 };
	Gradient::Texture diffuse(100, 100, Vector3(1.0f, 0.5f, 0.31f), Gradient::TextureType::Default);
	Gradient::Texture specular(100, 100, Vector3(1.0f, 1.0f, 1.0f), Gradient::TextureType::Default);
	float shininess = 32.0f;
	Gradient::Material material = { diffuse, specular, shininess };
	Gradient::Mesh3D mesh(vertices, indices, material);
	model = new Gradient::Model3D(std::vector<Gradient::Mesh3D>{mesh}, glm::rotate(Matrix4(1.0f), glm::radians(30.0f), Vector3(0.0f, 1.0f, 0.0f)));
	shader = new Gradient::Shader("../Gradient/src/Gradient/Shaders/Phong.glsl");
	cam = new Gradient::PerspectiveCamera(Vector3(0.0f, 0.0f, 2.0f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f), 4.0f, 3.0f, 90.0f, 0.01f, 100.0f);
	
	renderer = new Gradient::Renderer(*cam);
	*/
}

void GameScope::OnDetach()
{
	//delete renderer, cam, model, shader;
}

void GameScope::OnEvent(Gradient::Event& e)
{

}

void GameScope::OnUpdate()
{
	/*
	renderer->SetClearColor(Vector3(0.0f, 0.0f, 0.0f));
	renderer->BeginFrame();

	std::vector<Gradient::Light*> lights = { &Gradient::PointLight(Vector3(0.15f, 0.15f, 0.15f), Vector3(0.5f, 0.5f, 0.5f),
		Vector3(1.0f, 1.0f, 1.0f), Vector3(1.5f, 1.0f, 2.0f)) };

	renderer->DrawModel(*model, *shader, lights);

	renderer->EndFrame();
	*/
}