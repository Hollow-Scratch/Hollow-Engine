#include "Application.h"

namespace Hollow {

	void Application::Run() {
		// Initialize once
		OnInit();

		// Main loop
		while (m_Running) {
			OnUpdate();
		}

		// Cleanup
		OnShutdown();
	}

} // namespace Hollow
