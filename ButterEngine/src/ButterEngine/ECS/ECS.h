#pragma once
#include "ButterEngine/Core.h"
#include "btrpch.h"

namespace Butter
{

	/*
	// --------------------------------------------------------------------- //
	// ENTITY
	// --------------------------------------------------------------------- //

	class BUTTER_API Entity
	{
	public:

		Entity(uint32_t id) : id(id) {}
		inline uint32_t GetID() { return id; }
	private:
		const uint32_t id;
		
	};


	// --------------------------------------------------------------------- //
	// COMPONENT
	// --------------------------------------------------------------------- //

	class BUTTER_API Component
	{

	public:

		Component()
		{
			
		}

		~Component() {};
	};

	// --------------------------------------------------------------------- //
// ENTITY MANAGER
// --------------------------------------------------------------------- //

	class BUTTER_API EntityManager
	{
		static EntityManager * instance;

	public:
		std::unordered_map<std::shared_ptr<Entity>, std::vector<std::shared_ptr<Component>>> entityComponentMap;

	public:

		std::shared_ptr<Entity> CreateEntity()
		{
			std::shared_ptr<Entity> entity = std::make_shared<Entity>(entityID);

			entityComponentMap.emplace(entity);

			entityID++;

			return entity;
		}

		void DestroyEntity()
		{

		}

		template<typename T>
		void AddComponent(std::shared_ptr<Entity> entity, std::shared_ptr<T> component)
		{
			//entityComponentMap.at(entity).push_back(component);
			//BTR_INFO("Added component to entity");
		}


	private:
		uint32_t entityID = 0;
	};

		*/
}