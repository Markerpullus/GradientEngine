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
		OrthographicCameraHandler(Actor& a)
			: Handler(HandlerType::OrthographicCamera, &a)
		{ };
		~OrthographicCameraHandler() = default;

		virtual void OnInit() override;

		virtual void OnUpdate() override;

		virtual void OnDestroy() override;
	};

	class PerspectiveCameraHandler: public Handler
	{
	private:
		std::unique_ptr<PerspectiveCamera> camera;

	public:
		PerspectiveCameraHandler(Actor& a)
			: Handler(HandlerType::PerspectiveCamera, &a)
		{ };
		~PerspectiveCameraHandler() = default;

		virtual void OnInit() override;

		virtual void OnUpdate() override;

		virtual void OnDestroy() override;
	};
}
