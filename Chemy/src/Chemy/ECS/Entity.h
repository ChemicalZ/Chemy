#pragma once

#include "Chemy\Core.h"

#include "Component.h"

namespace Chemy {

	struct CHEMY_API Entity {
		std::bitset<32> componentmask_ = componentmask_.reset();
		int entityid_;
		//Modify mask_ to properly reflect used components
		void AddComponent(const int);
		void RemoveComponent(const int);
		bool HasComponent(const int);
		int GetEntityID();
	};


}