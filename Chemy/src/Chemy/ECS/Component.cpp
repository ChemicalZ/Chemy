#pragma once

#include "czpch.h"
#include "Component.h"

#include "Chemy/Core.h"
#include "Chemy/Log/Log.h"




namespace Chemy{
	// Initialize Component class
	int Component::currentid_ = 0;
	std::map<std::string, int> Component::maskdict_;

	Component::Component(std::string name) :
		componentname_(name) {
		// Check to see if the Component limit has been reach. (Only 32 bits in my bitfield)
		if (Component::currentid_ != 32) {
			// check to see if the Component is already registered
			auto search = maskdict_.find(name);
			if (search != maskdict_.end()) {
				const int mask = search->second;
			}
			// if the Component is not registered
			else {
				maskdict_.emplace(name, ++currentid_);
				const int mask = currentid_;
			}
		}
		else {
			CZ_CORE_WARN("Maximum number of Component Types reached! ({})",Component::currentid_);
		}
	}

}