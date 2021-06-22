#include "Gradient/Core/Input.h"
#include "Gradient/Core/Application.h"

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

	glm::vec2 Input::GetMousePos()
	{
		double xpos, ypos;
		glfwGetCursorPos(Application::GetSelf()->GetWindow().GetGLFWwindow(), &xpos, &ypos);
		return glm::vec2((float)xpos, (float)ypos);
	}
}