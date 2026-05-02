#include "Application.hpp"
#include "Engine/Core/Window.hpp"

namespace Hollow {

	Application::~Application() = default;

	void Application::Run() {
		m_Window = Window::Create();
		OnInit();

		while (m_Running && !m_Window->ShouldClose()) {
			m_Window->OnUpdate();
			OnUpdate();
		}

		OnShutdown();
	}

	void Application::Close() {
		m_Running = false;
	}

} // namespace Hollow