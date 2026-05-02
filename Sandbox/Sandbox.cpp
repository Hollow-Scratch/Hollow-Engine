#include "Engine/Core/KeyCodes.hpp"
#include "Engine/Hollow.hpp"

#include "iostream"
#include <memory>

namespace Hollow {

	class Sandbox : public Hollow::Application {
	      protected:
		void OnInit() override {
			// init
		}

		void OnUpdate() override {
			// update
			if (Input::IsKeyPressed(KeyCode::Escape)) {
				Close();
			}
		}

		void OnShutdown() override {
			// cleanup
		}
	};

} // namespace Hollow

std::unique_ptr<Hollow::Application> Hollow::CreateApplication() {
	return std::make_unique<Sandbox>();
}
