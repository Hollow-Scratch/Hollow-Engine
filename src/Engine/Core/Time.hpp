#pragma once

#include "Core.hpp"

namespace Hollow {

	class HOLLOW_API Time {
	      public:
		static void Init();
		static void Update();

		[[nodiscard]] static float GetTime();
		[[nodiscard]] static float GetUnscaledTime();
		[[nodiscard]] static float GetDeltaTime();
		[[nodiscard]] static float GetUnscaledDeltaTime();

		static void SetTimeScale(float scale);
		[[nodiscard]] static float GetTimeScale();

		static void Pause(bool paused);
		[[nodiscard]] static bool IsPaused();

	      private:
		static float s_Time;
		static float s_UnscaledTime;

		static float s_DeltaTime;
		static float s_UnscaledDeltaTime;

		static float s_TimeScale;
		static bool s_Paused;

		static double s_LastTime;
	};

} // namespace Hollow