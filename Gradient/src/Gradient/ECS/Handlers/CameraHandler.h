#pragma once

#include "Gradient/ECS/Handlers/Handler.h"
#include "Gradient/Rendering/Camera/OrthographicCamera.h"
#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

#include <memory>

namespace Gradient
{
	class OrthographicCameraHandler : public Handler
	{
	private:
		std::unique_ptr<OrthographicCamera> camera;

	public:
		OrthographicCameraHandler()
			: Handler(HandlerType::OrthographicCamera)
		{ };
		~OrthographicCameraHandler() = default;

		virtual void OnInit() override;

		virtual void OnUpdate() override;
	};

	class PerspectiveCamera : public Handler
	{
	private:
		std::unique_ptr<PerspectiveCamera> camera;

	public:
		PerspectiveCamera()
			: Handler(HandlerType::PerspectiveCamera)
		{ };
		~PerspectiveCamera() = default;

		virtual void OnInit() override;

		virtual void OnUpdate() override;
	};
}
