#pragma once

#include "KeyCodes.hpp"
#include "MouseCodes.hpp"
#include <unordered_map>

namespace Hollow {

	struct MousePosition {
		float X;
		float Y;
	};

	class Input {
	      public:
		static bool IsKeyPressed(KeyCode key);	// held
		static bool IsKeyDown(KeyCode key);	// pressed once
		static bool IsKeyReleased(KeyCode key); // released once

		static bool IsMouseButtonPressed(MouseButton button);

		static MousePosition GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		static void SetNativeWindow(void *window);

		static void Update();

	      private:
		static std::unordered_map<KeyCode, bool> s_CurrentKeys;
		static std::unordered_map<KeyCode, bool> s_PreviousKeys;
	};

} // namespace Hollow