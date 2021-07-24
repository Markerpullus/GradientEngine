#include "Gradient/ECS/Handlers/CameraHandler.h"
#include "Gradient/Math/Math.h"

namespace Gradient
{
	void OrthographicCameraHandler::OnInit()
	{
		camera = std::make_unique<OrthographicCamera>(OrthographicCamera(800.0f, 600.0f));
	}

	void OrthographicCameraHandler::OnUpdate()
	{
		/* I'll fix this another day
		auto& transform = *(Component::Transform*)owner->GetComponent<Component::Transform>();
		auto& cam = *(Component::OrthographicCamera*)owner->GetComponent<Component::OrthographicCamera>();
		camera->SetPosition(transform.translation);
		camera->SetOrientation(transform.rotation * Vector3(0, 0, -1));
		camera->SetUpVector(transform.rotation * Vector3(0, 1, 0));
		camera->SetZFar(cam.zFar);
		camera->SetZNear(cam.zNear);
		camera->SetDimensions(cam.width, cam.height);
		*/
	}

	void OrthographicCameraHandler::OnDestroy()
	{
	}

	void PerspectiveCameraHandler::OnInit()
	{
		camera = std::make_unique<PerspectiveCamera>(PerspectiveCamera(800.0f, 600.0f));
	}

	void PerspectiveCameraHandler::OnUpdate()
	{
	}
	void PerspectiveCameraHandler::OnDestroy()
	{
	}
}