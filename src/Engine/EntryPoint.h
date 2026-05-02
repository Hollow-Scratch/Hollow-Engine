#pragma once
#include "Core/Application.h"
#include <memory>

namespace Hollow {
	std::unique_ptr<Application> CreateApplication();
}

int main() {
	auto app = Hollow::CreateApplication();
	app->Run();
	return 0;
}