#pragma once
#include "ButterEngine/Core/Core.h"
#include "btrpch.h"

namespace Butter
{

	
	// --------------------------------------------------------------------- //
	// OBJECT
	// --------------------------------------------------------------------- //

	class BUTTER_API Object
	{
	public:


		Object(uint32_t id) : id(id) {}
		Object(uint32_t id, std::string tempName) : id(id) { }

		const uint32_t id;

		std::string data;
		

	private:
		
		
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
// OBJECT MANAGER
// --------------------------------------------------------------------- //

	class BUTTER_API ObjectManager
	{
		static ObjectManager * instance;

	public:
		//std::unordered_map<std::shared_ptr<Object>, std::vector<std::shared_ptr<Component>>> objectComponentMap;

	public:

		std::shared_ptr<Object> CreateObject()
		{
			std::shared_ptr<Object> object = std::make_shared<Object>(objectID);

			//entityComponentMap.emplace(entity);

			objectID++;

			return object;
		}

		std::shared_ptr<Object> CreateObjectFromTemplate(std::string templateName)
		{
			std::shared_ptr<Object> object = std::make_shared<Object>(objectID, templateName);
		}

		void DestroyEntity()
		{

		}

		template<typename T>
		void AddComponent(std::shared_ptr<Object> object, std::shared_ptr<T> component)
		{
			//entityComponentMap.at(entity).push_back(component);
			//BTR_INFO("Added component to entity");
		}


	private:
		uint32_t objectID = 0;
	};

		
}