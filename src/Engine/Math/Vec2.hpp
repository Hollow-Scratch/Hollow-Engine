#pragma once

namespace Hollow {

	struct Vec2 {
		float x, y;

		Vec2() : x(0), y(0) {
		}
		Vec2(float x, float y) : x(x), y(y) {
		}

		Vec2 operator+(const Vec2 &o) const {
			return {x + o.x, y + o.y};
		}
		Vec2 operator-(const Vec2 &o) const {
			return {x - o.x, y - o.y};
		}
		Vec2 operator*(float s) const {
			return {x * s, y * s};
		}
	};

} // namespace Hollow
