#include "Input.hpp"
#include <GLFW/glfw3.h>

namespace Hollow {

	static GLFWwindow *s_WindowHandle = nullptr;

	void Input::SetNativeWindow(void *window) {
		s_WindowHandle = static_cast<GLFWwindow *>(window);
	}

	bool Input::IsKeyPressed(KeyCode keycode) {
		if (!s_WindowHandle)
			return false;

		auto state = glfwGetKey(s_WindowHandle, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseButton button) {
		if (!s_WindowHandle)
			return false;

		auto state = glfwGetMouseButton(s_WindowHandle, button);
		return state == GLFW_PRESS;
	}

	MousePosition Input::GetMousePosition() {
		if (!s_WindowHandle)
			return {0.0f, 0.0f};

		double x, y;
		glfwGetCursorPos(s_WindowHandle, &x, &y);

		return {static_cast<float>(x), static_cast<float>(y)};
	}

	float Input::GetMouseX() {
		return GetMousePosition().X;
	}

	float Input::GetMouseY() {
		return GetMousePosition().Y;
	}

} // namespace Hollow