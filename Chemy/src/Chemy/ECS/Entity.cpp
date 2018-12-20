#pragma once

#include "czpch.h"
#include "Entity.h"
#include "Chemy\Core.h"


namespace Chemy {

	void Entity::AddComponent(const int comp) {

		componentmask_.set(comp);
	}
	void Entity::RemoveComponent(const int comp) {
		componentmask_.reset(comp);
	}
	bool Entity::HasComponent(const int comp) {
		return componentmask_.test(comp);
	}
	int Entity::GetEntityID() {
		return entityid_;
	}


}