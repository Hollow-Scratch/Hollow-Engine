#pragma once

#include "Core.hpp"

#include <memory>

namespace Hollow {

	class Window;

	class HOLLOW_API Application {
	      public:
		Application() = default;
		virtual ~Application();

		void Run();
		void Close();

	      protected:
		virtual void OnInit() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
		virtual void OnShutdown() = 0;

	      private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

} // namespace Hollow