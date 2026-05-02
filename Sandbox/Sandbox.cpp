#include "Engine/Hollow.hpp"

#include "GLFW/glfw3.h" // For GLFW_KEY_ESCAPE

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
		if(Input::IsKeyPressed(GLFW_KEY_ESCAPE)) {
			Close();
		}
	}

	void OnShutdown() override {
		// cleanup
	}
};

}

std::unique_ptr<Hollow::Application> Hollow::CreateApplication() {
	return std::make_unique<Sandbox>();
}
