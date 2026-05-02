#pragma once
#include <cstdint>

namespace Hollow {

	using KeyCode = int;
	using MouseButton = int;

	struct MousePosition {
		float X;
		float Y;
	};

	class Input {
	public:
		[[nodiscard]] static bool IsKeyPressed(KeyCode keycode);
		[[nodiscard]] static bool IsMouseButtonPressed(MouseButton button);

		[[nodiscard]] static MousePosition GetMousePosition();
		[[nodiscard]] static float GetMouseX();
		[[nodiscard]] static float GetMouseY();

		static void SetNativeWindow(void* window);
	};

} // namespace Hollow