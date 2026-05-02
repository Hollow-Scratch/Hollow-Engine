#include "Time.hpp"
#include <chrono>

namespace Hollow {

	using Clock = std::chrono::high_resolution_clock;

	float Time::s_Time = 0.0f;
	float Time::s_UnscaledTime = 0.0f;

	float Time::s_DeltaTime = 0.0f;
	float Time::s_UnscaledDeltaTime = 0.0f;

	float Time::s_TimeScale = 1.0f;
	bool Time::s_Paused = false;

	double Time::s_LastTime = 0.0;

	void Time::Init() {
		auto now = Clock::now().time_since_epoch();
		s_LastTime = std::chrono::duration<double>(now).count();
	}

	void Time::Update() {
		auto now = Clock::now().time_since_epoch();
		double currentTime = std::chrono::duration<double>(now).count();

		s_UnscaledDeltaTime = static_cast<float>(currentTime - s_LastTime);
		s_LastTime = currentTime;

		s_UnscaledTime += s_UnscaledDeltaTime;

		if (s_Paused) {
			s_DeltaTime = 0.0f;
			return;
		}

		s_DeltaTime = s_UnscaledDeltaTime * s_TimeScale;
		s_Time += s_DeltaTime;
	}

	float Time::GetTime() {
		return s_Time;
	}

	float Time::GetUnscaledTime() {
		return s_UnscaledTime;
	}

	float Time::GetDeltaTime() {
		return s_DeltaTime;
	}

	float Time::GetUnscaledDeltaTime() {
		return s_UnscaledDeltaTime;
	}

	void Time::SetTimeScale(float scale) {
		s_TimeScale = scale;
	}

	float Time::GetTimeScale() {
		return s_TimeScale;
	}

	void Time::Pause(bool paused) {
		s_Paused = paused;
	}

	bool Time::IsPaused() {
		return s_Paused;
	}

} // namespace Hollow