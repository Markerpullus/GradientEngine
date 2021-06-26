#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API PerspectiveCamera : Camera
	{
	private:
		float zNear, zFar;

	public:
		PerspectiveCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h, float fov, float znear, float zfar);
		~PerspectiveCamera() = default;

		void SetPosition(Vector3 p);

		void SetRotation(Vector3 r);

		void SetUpVector(Vector3 u);

		inline CameraData GetCamData() { return cam; }

		void DrawMesh2D(Mesh2D& mesh) override;

		void DrawMesh3D(Mesh3D& mesh) override;
	};
}
