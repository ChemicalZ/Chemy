#pragma once


#include "Chemy\Core.h"

#include "Chemy/EventSystem/Listener.h"
#include "Component.h"
#include "Entity.h"

namespace Chemy {

	class CHEMY_API BaseSystem : public Listener {
	public:
		// Keep track of all Systems
		static Entity* s_Entities;
		static void Init(Entity*);

		// Register Systems to BaseSystem
		static std::vector<BaseSystem*> s_Systems;
		static void Register(BaseSystem*);
		static void Unregister(BaseSystem*);
		
		//Manage System
		std::map<std::string, Component*> componentlist_;
		void AddComponent(std::string, Component*);
		void RemoveComponent(std::string, Component*);
		
		// Listener
		virtual void OnEvent(Event) = 0;

	private:


	};

}