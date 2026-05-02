#pragma once

#include "Engine/Core/Window.hpp"
#include <GLFW/glfw3.h>

namespace Hollow {

	class GLFWWindow final : public Window {
	      public:
		explicit GLFWWindow(const WindowProps &props);
		~GLFWWindow() override;

		void OnUpdate() override;

		[[nodiscard]] uint32_t GetWidth() const noexcept override;
		[[nodiscard]] uint32_t GetHeight() const noexcept override;

		void SetVSync(bool enabled) override;
		[[nodiscard]] bool IsVSync() const noexcept override;

		[[nodiscard]] bool ShouldClose() const noexcept override;

		void SetEventCallback(const EventCallbackFn &callback) override;

		[[nodiscard]] GLFWwindow *GetNativeWindow() const noexcept override;

	      private:
		void Init(const WindowProps &props);
		void Shutdown();

		GLFWwindow *m_Window{nullptr};

		struct Data {
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			bool VSync{true};

			EventCallbackFn EventCallback;
		} m_Data;
	};

} // namespace Hollow