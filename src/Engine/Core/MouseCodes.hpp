#pragma once
#include <cstdint>

namespace Hollow {

	enum class MouseButton : uint8_t {
		Button0 = 0,
		Button1,
		Button2,
		Button3,
		Button4,
		Button5,
		Button6,
		Button7,

		Left = Button0,
		Right = Button1,
		Middle = Button2
	};

}