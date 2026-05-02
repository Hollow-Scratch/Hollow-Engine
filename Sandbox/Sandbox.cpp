#include "Engine/Hollow.h"
#include "iostream"
#include <memory>

class Sandbox : public Hollow::Application {
      protected:
	void OnInit() override {
		// init
	}

	void OnUpdate() override {
		// update
		std::cout << "update";
	}

	void OnShutdown() override {
		// cleanup
	}
};

std::unique_ptr<Hollow::Application> Hollow::CreateApplication() {
	return std::make_unique<Sandbox>();
}
