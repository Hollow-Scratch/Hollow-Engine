#pragma once
#include "Vec3.hpp"

namespace Hollow {

	struct Mat4 {
		float data[16];

		static Mat4 Identity();
		static Mat4 Translate(const Vec3 &v);
		static Mat4 Rotate(float angle, const Vec3 &axis);
		static Mat4 Scale(const Vec3 &v);
		static Mat4 Perspective(float fov, float aspect, float near, float far);

		Mat4 operator*(const Mat4 &other) const;
	};

} // namespace Hollow
