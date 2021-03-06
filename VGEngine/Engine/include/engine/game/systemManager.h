
#pragma once

#include "engine/game/gameObject.h"
#include "engine/game/system.h"

#include <vector>

namespace vg
{
	/**
	Manages componentSystems
	*/
	class SystemManager
	{
		friend class Scene;
	public:
		SystemManager();
		~SystemManager();

		/**
		Updates the components inside the gameObject
		@param gameObject The gameObject that is going to be updated inside the componentSystems
		*/
		void update(std::vector<GameObject*> *gameObjects,float deltaTime);

		/**
		@param system to be added
		*/
		void addSystem(System *system);
		
		/**
		Deletes all systems
		*/
		void clearSystems();
		
		/**
		@return list of all current systems
		*/
		std::vector<System*> *getAllSystems() { return &systems; };

		/**
		@return system with template type from system list.
		*/
		template<typename T> 
		T *getSystem()
		{
			for (auto it = systems.begin(); it != systems.end(); it++)
			{
				T* system = dynamic_cast<T*>((*it));
				if (system != nullptr)
					return system;
			}
			return nullptr;
		}
	private:

		void addDefaultSystems();

		std::vector<System*> systems;	///< current systems
	};

}