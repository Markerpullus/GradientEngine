#pragma once

#include <Gradient/Core/Scope.h>
#include <Gradient/Rendering/Renderer.h>
#include <Gradient/Rendering/Camera/PerspectiveCamera.h>

class GameScope : public Gradient::Scope
{
private:
	Gradient::Renderer* renderer;
	Gradient::PerspectiveCamera* cam;
	Gradient::Model3D* model;
	Gradient::Shader* shader;

public:
	GameScope();
	~GameScope() = default;

	virtual void OnAttach() override;

	virtual void OnDetach() override;

	virtual void OnEvent(Gradient::Event& e) override;

	virtual void OnUpdate() override;
};

