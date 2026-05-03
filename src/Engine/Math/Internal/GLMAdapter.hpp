#pragma once

#include <glm/glm.hpp>
#include <cstring>

#include "../Mat4.hpp"

namespace Hollow {

	inline glm::mat4 ToGLM(const Mat4 &m) {
		glm::mat4 out;
		std::memcpy(&out, m.data, sizeof(float) * 16);
		return out;
	}

	inline Mat4 FromGLM(const glm::mat4 &m) {
		Mat4 out;
		std::memcpy(out.data, &m, sizeof(float) * 16);
		return out;
	}

} // namespace Hollow
