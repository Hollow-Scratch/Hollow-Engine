#include "Engine/Hollow.hpp"

#include <iostream>
#include <memory>

namespace Hollow {

	class Sandbox : public Application {
	      protected:
		Registry registry;
		Entity player = INVALID_ENTITY;

		// Movement system (position update)
		void MovementSystem(float dt) {
			auto &transforms = registry.view<Transform>();
			auto &velocities = registry.view<Velocity>();

			for (auto &[entity, t] : transforms) {
				if (!registry.has<Velocity>(entity))
					continue;

				auto &v = velocities[entity];

				t.x += v.vx * dt;
				t.y += v.vy * dt;
			}
		}

		void OnInit() override {
			std::cout << "OnInit called\n";

			player = registry.create();

			registry.add(player, Transform{0.0f, 0.0f});
			registry.add(player, Velocity{10.0f, 0.0f});
		}

		void OnUpdate(float deltaTime) override {
			auto &v = registry.get<Velocity>(player);

			float speed = 100.0f;

			// reset every frame (correct)
			v.vx = 0.0f;
			v.vy = 0.0f;

			// continuous input
			if (Input::IsKeyPressed(KeyCode::Left))
				v.vx = -speed;

			if (Input::IsKeyPressed(KeyCode::Right))
				v.vx = speed;

			if (Input::IsKeyPressed(KeyCode::Up))
				v.vy = speed;

			if (Input::IsKeyPressed(KeyCode::Down))
				v.vy = -speed;

			MovementSystem(deltaTime);

			// Debug output
			auto &t = registry.get<Transform>(player);
			std::cout << "Pos: " << t.x << ", " << t.y << "\n";

			// Exit
			if (Input::IsKeyPressed(KeyCode::Escape)) {
				Close();
			}
		}

		void OnShutdown() override {
			std::cout << "Shutdown\n";
		}
	};

} // namespace Hollow

std::unique_ptr<Hollow::Application> Hollow::CreateApplication() {
	return std::make_unique<Hollow::Sandbox>();
}