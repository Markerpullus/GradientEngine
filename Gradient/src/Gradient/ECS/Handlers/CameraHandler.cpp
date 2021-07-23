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
		camera->SetPosition(owner->GetComponent<Component::Transform>().translation);
		Vector3 rotation = owner->GetComponent<Component::Transform>().rotation;
		camera->SetOrientation(Vector3(cos(rotation.z)*cos(rotation.x),
			sin(rotation.x),
			sin(rotation.z)*cos(rotation.x)));
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