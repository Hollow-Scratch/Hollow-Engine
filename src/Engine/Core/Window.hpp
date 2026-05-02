#pragma once

#include "Core.hpp"

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

struct GLFWwindow;

namespace Hollow {

	struct WindowProps {
		std::string Title{"Hollow Engine"};
		uint32_t Width{1280};
		uint32_t Height{720};
		bool VSync{true};
	};

	class HOLLOW_API Window {
	      public:
		using EventCallbackFn =
		    std::function<void(int)>; // Placeholder for actual event type

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		[[nodiscard]] virtual uint32_t GetWidth() const noexcept = 0;
		[[nodiscard]] virtual uint32_t GetHeight() const noexcept = 0;

		virtual void SetVSync(bool enabled) = 0;
		[[nodiscard]] virtual bool IsVSync() const noexcept = 0;

		[[nodiscard]] virtual bool ShouldClose() const noexcept = 0;

		virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

		[[nodiscard]] virtual GLFWwindow *GetNativeWindow() const noexcept = 0;

		static std::unique_ptr<Window> Create(const WindowProps &props = {});
	};

} // namespace Hollow