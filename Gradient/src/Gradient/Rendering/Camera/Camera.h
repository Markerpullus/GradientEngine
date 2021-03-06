#pragma once

#include "Gradient//Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Model/Model.h"
#include "Gradient/Rendering/Light.h"

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
		CameraData cam = { Matrix4(1.0f), Matrix4(1.0f) };
		Vector3 position = Vector3(0.0f);
		Vector3 orientation = Vector3(0.0f, 0.0f, -1.0f);
		Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
		float width, height;
		float zNear = 0.01f, zFar = 100.0f;

		virtual void RecalcProjection() = 0;

	public:
		Camera(float w, float h);
		~Camera() = default;

		void SetPosition(Vector3 p);

		void SetOrientation(Vector3 r);

		void SetUpVector(Vector3 u);

		void SetDimensions(float w, float h);

		inline CameraData GetCamData() { return cam; }

		friend class Renderer;
	};
}
