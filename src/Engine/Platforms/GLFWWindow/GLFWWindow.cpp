#include "GLFWWindow.hpp"
#include "Engine/Core/Input.hpp"

#include <iostream>
#include <stdexcept>

namespace Hollow {

	static bool s_GLFWInitialized = false;

	GLFWWindow::GLFWWindow(const WindowProps &props) {
		Init(props);
	}

	GLFWWindow::~GLFWWindow() {
		Shutdown();
	}

	void GLFWWindow::Init(const WindowProps &props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (!s_GLFWInitialized) {
			if (glfwInit() == 0) {
				throw std::runtime_error("Failed to init GLFW");
			}

			// Request OpenGL 4.6 Core
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(static_cast<int>(m_Data.Width),
					    static_cast<int>(m_Data.Height), m_Data.Title.c_str(),
					    nullptr, nullptr);

		if (!m_Window) {
			throw std::runtime_error("Failed to create GLFW window");
		}

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			throw std::runtime_error("Failed to initialize GLAD");
		}

		const GLubyte *version = glGetString(GL_VERSION);
		if (!version) {
			throw std::runtime_error("Failed to get OpenGL version");
		}

		std::cout << "OpenGL Version: " << version << "\n";

		Input::SetNativeWindow(m_Window);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
			auto &data = *static_cast<Data *>(glfwGetWindowUserPointer(window));
			data.Width = static_cast<uint32_t>(width);
			data.Height = static_cast<uint32_t>(height);
		});

		SetVSync(props.VSync);
	}

	void GLFWWindow::Shutdown() {
		if (m_Window) {
			glfwDestroyWindow(m_Window);
			m_Window = nullptr;
		}
	}

	void GLFWWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void GLFWWindow::SetVSync(bool enabled) {
		glfwSwapInterval(enabled ? 1 : 0);
		m_Data.VSync = enabled;
	}

	bool GLFWWindow::IsVSync() const noexcept {
		return m_Data.VSync;
	}

	bool GLFWWindow::ShouldClose() const noexcept {
		return glfwWindowShouldClose(m_Window) != 0;
	}

	void GLFWWindow::SetEventCallback(const EventCallbackFn &callback) {
		m_Data.EventCallback = callback;
	}

	GLFWwindow *GLFWWindow::GetNativeWindow() const noexcept {
		return m_Window;
	}

	uint32_t GLFWWindow::GetWidth() const noexcept {
		return m_Data.Width;
	}

	uint32_t GLFWWindow::GetHeight() const noexcept {
		return m_Data.Height;
	}

} // namespace Hollow