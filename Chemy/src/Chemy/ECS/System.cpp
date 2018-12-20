#pragma once

#include "czpch.h"
#include "System.h"

#include "Chemy\Core.h"
#include "Chemy/Log/Log.h"

#include "Component.h"
#include "Entity.h"

namespace Chemy {

	//Initialize static variables
	Entity* BaseSystem::s_Entities;
	std::vector<BaseSystem*> BaseSystem::s_Systems;

	void BaseSystem::Init(Entity* EntityList) {
		BaseSystem::s_Entities = EntityList;
	}

	// Register Systems to BaseSystem
	//static std::vector<BaseSystem*> s_Systems;
	void BaseSystem::Register(BaseSystem* newSystem) {
		bool isIn = false;
		for (auto it : s_Systems) {
			if (it == newSystem) {
				isIn = true;
			}
		}
		if (isIn)
			CZ_CORE_INFO("The System at addres is already register");
		else
			s_Systems.push_back(newSystem);

	}
	void BaseSystem::Unregister(BaseSystem* sys) {
		bool isIn = false;

		for (auto it = s_Systems.begin(); it != s_Systems.end(); ++it) {
			if (*it == sys) {
				s_Systems.erase(it);
			}
		}
		if (!isIn)
			CZ_CORE_INFO("The System at address is NOT registered");
	}

	//Manage System
	void BaseSystem::AddComponent(std::string type, Component* comp) {
		auto search = componentlist_.find(type);
		if (search == componentlist_.end()){
			componentlist_.emplace(type, comp);
		}
		else {
			CZ_CORE_WARN("You can not add more than one Component of the Same type");
		}
	}

	void BaseSystem::RemoveComponent(std::string type, Component* comp) {
		auto search = componentlist_.find(type);
		if (search != componentlist_.end()) {
			componentlist_.erase(search);
		}
		else {
			CZ_CORE_WARN("The Component is not associated with this System");
		}
	}

}