#include "Gradient/Core/Application.h"
#include "Gradient/Core/Input.h"

namespace Gradient
{
	bool Input::IsKeyPressed(KeyCode key)
	{
		int keyStatus = glfwGetKey(Application::GetSelf()->GetWindow().GetGLFWwindow(), (int)key);
		return (keyStatus == GLFW_PRESS) || (keyStatus == GLFW_REPEAT);
	}

	bool Input::IsMouseButtonPressed(MouseCode button)
	{
		int mouseStatus = glfwGetMouseButton(Application::GetSelf()->GetWindow().GetGLFWwindow(), (int)button);
		return (mouseStatus == GLFW_PRESS) || (mouseStatus == GLFW_REPEAT);
	}

	Vector2 Input::GetMousePos()
	{
		glm::dvec2 pos;
		glfwGetCursorPos(Application::GetSelf()->GetWindow().GetGLFWwindow(), &pos.x, &pos.y);
		return (glm::vec2)pos;
	}
}