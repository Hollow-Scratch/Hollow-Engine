#include "Application.hpp"
#include "Engine/Core/Window.hpp"
#include "Input.hpp"
#include "Time.hpp"

namespace Hollow {

	Application::~Application() = default;

	void Application::Run() {
		m_Window = Window::Create();

		Time::Init();
		OnInit();

		while (m_Running && !m_Window->ShouldClose()) {
			Time::Update();
			Input::Update();
			OnUpdate(Time::GetDeltaTime());
			m_Window->OnUpdate();
		}

		OnShutdown();
	}

	void Application::Close() {
		m_Running = false;
	}

} // namespace Hollow