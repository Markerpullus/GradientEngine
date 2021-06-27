#pragma once

#include "Gradient//Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Model/Mesh2D.h"
#include "Gradient/Rendering/Model/Mesh3D.h"

namespace Gradient
{
	struct CameraData
	{
		Matrix4 view;
		Matrix4 projection;
	};

	class GD_API Camera
	{
	protected:
		CameraData cam;
		Vector3 position;
		Vector3 rotation;
		Vector3 up;
		float width, height;

	public:
		Camera(Vector3 p, Vector3 r, Vector3 u, float w, float h)
			: position(p), rotation(r), up(u), width(w), height(h)
		{ };
		~Camera() = default;

		inline virtual void SetPosition(Vector3 p) { position = p; }

		inline virtual void SetRotation(Vector3 r) { rotation = r; }

		inline virtual void SetUpVector(Vector3 u) { up = u; }

		inline CameraData GetCamData() { return cam; }

		virtual void DrawMesh2D(Mesh2D& mesh) = 0;

		virtual void DrawMesh3D(Mesh3D& mesh) = 0;
	};
}
