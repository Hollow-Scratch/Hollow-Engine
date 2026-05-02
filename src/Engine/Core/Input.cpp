#include "Input.hpp"
#include "GLFWKeyMapper.hpp"
#include <GLFW/glfw3.h>

namespace Hollow {

	static GLFWwindow *s_WindowHandle = nullptr;

	std::unordered_map<KeyCode, bool> Input::s_CurrentKeys;
	std::unordered_map<KeyCode, bool> Input::s_PreviousKeys;

	void Input::SetNativeWindow(void *window) {
		s_WindowHandle = static_cast<GLFWwindow *>(window);
	}

	void Input::Update() {

		s_PreviousKeys = s_CurrentKeys;

		for (int key = 32; key <= 348; key++) {
			KeyCode engineKey = GLFWToKeyCode(key);
			if (engineKey == KeyCode::Unknown)
				continue;

			int state = glfwGetKey(s_WindowHandle, key);
			s_CurrentKeys[engineKey] = (state == GLFW_PRESS || state == GLFW_REPEAT);
		}
	}

	bool Input::IsKeyPressed(KeyCode key) {
		return s_CurrentKeys[key];
	}

	bool Input::IsKeyDown(KeyCode key) {
		return s_CurrentKeys[key] && !s_PreviousKeys[key];
	}

	bool Input::IsKeyReleased(KeyCode key) {
		return !s_CurrentKeys[key] && s_PreviousKeys[key];
	}

	bool Input::IsMouseButtonPressed(MouseButton button) {
		auto state = glfwGetMouseButton(s_WindowHandle, static_cast<int>(button));
		return state == GLFW_PRESS;
	}

	MousePosition Input::GetMousePosition() {
		double x, y;
		glfwGetCursorPos(s_WindowHandle, &x, &y);
		return {(float)x, (float)y};
	}

	float Input::GetMouseX() {
		return GetMousePosition().X;
	}
	float Input::GetMouseY() {
		return GetMousePosition().Y;
	}

} // namespace Hollow