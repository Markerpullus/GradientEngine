#pragma once

#include "Gradient//Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Model/Model.h"

namespace Gradient
{
	struct CameraData
	{
		Matrix4 view;
		Matrix4 projection;
	};

	class Camera
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

		void SetPosition(Vector3 p);
		
		void SetRotation(Vector3 r);
		
		void SetUpVector(Vector3 u);

		inline CameraData GetCamData() { return cam; }

		void DrawModel(Model2D& model);

		void DrawModel(Model3D& model);
	};
}
