#include "Gradient/ECS/Handlers/CameraHandler.h"

namespace Gradient
{
	void OrthographicCameraHandler::OnInit()
	{
		camera = std::make_unique<OrthographicCamera>(OrthographicCamera(800.0f, 600.0f));
	}

	void OrthographicCameraHandler::OnUpdate()
	{
		
	}

	void OrthographicCameraHandler::OnDestroy()
	{
	}

	void PerspectiveCameraHandler::OnInit()
	{
	}

	void PerspectiveCameraHandler::OnUpdate()
	{
	}
	void PerspectiveCameraHandler::OnDestroy()
	{
	}
}