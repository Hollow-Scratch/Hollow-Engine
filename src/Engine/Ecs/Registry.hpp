#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <cassert>

#include "Entity.hpp"

namespace Hollow {

	inline size_t GetUniqueComponentID() {
		static size_t lastID = 0;
		return lastID++;
	}

	template <typename T> inline size_t GetComponentTypeID() {
		static size_t typeID = GetUniqueComponentID();
		return typeID;
	}

	class Registry {
	      public:
		Entity create() {
			return nextEntity++;
		}

		template <typename T> void add(Entity e, const T &component) {
			getPool<T>().data[e] = component;
		}

		template <typename T> T &get(Entity e) {
			auto &pool = getPool<T>().data;
			assert(pool.find(e) != pool.end() && "Component missing");
			return pool[e];
		}

		template <typename T> bool has(Entity e) {
			auto &pool = getPool<T>().data;
			return pool.find(e) != pool.end();
		}

		template <typename T> std::unordered_map<Entity, T> &view() {
			return getPool<T>().data;
		}

	      private:
		struct IPool {
			virtual ~IPool() = default;
		};

		template <typename T> struct Pool : IPool {
			std::unordered_map<Entity, T> data;
		};

		template <typename T> Pool<T> &getPool() {
			size_t id = GetComponentTypeID<T>();

			if (id >= pools.size())
				pools.resize(id + 1);

			if (!pools[id])
				pools[id] = std::make_unique<Pool<T>>();

			return *static_cast<Pool<T> *>(pools[id].get());
		}

	      private:
		std::vector<std::unique_ptr<IPool>> pools;
		Entity nextEntity = 1;
	};

} // namespace Hollow