#include "Mat4.hpp"
#include "Internal/GLMAdapter.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Hollow {

	Mat4 Mat4::Identity() {
		return FromGLM(glm::mat4(1.0f));
	}

	Mat4 Mat4::Translate(const Vec3 &v) {
		return FromGLM(glm::translate(glm::mat4(1.0f), glm::vec3(v.x, v.y, v.z)));
	}

	Mat4 Mat4::Rotate(float angle, const Vec3 &axis) {
		return FromGLM(
		    glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis.x, axis.y, axis.z)));
	}

	Mat4 Mat4::Scale(const Vec3 &v) {
		return FromGLM(glm::scale(glm::mat4(1.0f), glm::vec3(v.x, v.y, v.z)));
	}

	Mat4 Mat4::Perspective(float fov, float aspect, float near, float far) {
		return FromGLM(glm::perspective(fov, aspect, near, far));
	}

	Mat4 Mat4::operator*(const Mat4 &other) const {
		return FromGLM(ToGLM(*this) * ToGLM(other));
	}

} // namespace Hollow
