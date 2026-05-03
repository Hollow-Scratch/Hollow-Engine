#include "Input.hpp"
#include "GLFWKeyMapper.hpp"

#include <GLFW/glfw3.h>
#include <cstring>

namespace Hollow {

	static GLFWwindow *s_WindowHandle = nullptr;

	// ✅ REQUIRED definitions
	bool Input::s_CurrentKeys[512] = {};
	bool Input::s_PreviousKeys[512] = {};

	void Input::SetNativeWindow(void *window) {
		s_WindowHandle = static_cast<GLFWwindow *>(window);
	}

	void Input::Update() {
		// copy current → previous
		std::memcpy(s_PreviousKeys, s_CurrentKeys, sizeof(s_CurrentKeys));

		// clear current state
		for (int i = 0; i < 512; i++)
			s_CurrentKeys[i] = false;

		// poll GLFW and map to your KeyCode
		for (int key = 32; key <= 348; key++) {
			KeyCode engineKey = GLFWToKeyCode(key);
			if (engineKey == KeyCode::Unknown)
				continue;

			int state = glfwGetKey(s_WindowHandle, key);
			s_CurrentKeys[(int)engineKey] =
			    (state == GLFW_PRESS || state == GLFW_REPEAT);
		}
	}

	bool Input::IsKeyPressed(KeyCode key) {
		return s_CurrentKeys[(int)key];
	}

	bool Input::IsKeyDown(KeyCode key) {
		return s_CurrentKeys[(int)key] && !s_PreviousKeys[(int)key];
	}

	bool Input::IsKeyReleased(KeyCode key) {
		return !s_CurrentKeys[(int)key] && s_PreviousKeys[(int)key];
	}

	bool Input::IsMouseButtonPressed(MouseButton button) {
		int state = glfwGetMouseButton(s_WindowHandle, static_cast<int>(button));
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