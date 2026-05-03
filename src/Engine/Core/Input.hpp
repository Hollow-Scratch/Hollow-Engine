#pragma once

#include "Core.hpp"
#include "KeyCodes.hpp"
#include "MouseCodes.hpp"

namespace Hollow {

	struct MousePosition {
		float X;
		float Y;
	};

	class HOLLOW_API Input {
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
		static bool s_CurrentKeys[512];
		static bool s_PreviousKeys[512];
	};

} // namespace Hollow