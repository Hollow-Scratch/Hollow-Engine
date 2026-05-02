#pragma once

namespace Hollow {
	class Application {
	      public:
		Application() = default;
		virtual ~Application() = default;

		void Run();

	      protected:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnShutdown() = 0;

	      private:
		bool m_Running = true;
	};

} // namespace Hollow
