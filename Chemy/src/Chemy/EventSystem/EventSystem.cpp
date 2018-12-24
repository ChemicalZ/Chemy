#pragma once

#include "czpch.h"
#include "EventSystem.h"


#include "Event.h"


namespace Chemy {
	//Clean up
	void EventSystem::Shutdown() {}
	//Add specific event_type OnEvent() to addressbook_
	bool EventSystem::Register(EVENT_TYPE id, Listener* call_back) {
		//Check to make sure the event is not already registered
		auto range = addressbook_.equal_range(id);
		for (auto it = range.first; it != range.second; ++it) {
			if (it->second == call_back) {
				return false;
			}

		}
		//Not found so add to list
		addressbook_.emplace(id, call_back);
		CZ_CORE_INFO("New Listener registered to: {}", id);
		return true;
	}
	//Remove specific Event_type OnEvent() from addressbook_
	bool EventSystem::Unregister(EVENT_TYPE id, Listener* call_back) {
		//Check to make sure the event is already registered
		auto range = addressbook_.equal_range(id);
		for (auto it = range.first; it != range.second; ++it) {
			if (it->second == call_back) {
				addressbook_.erase(it);
				CZ_CORE_INFO("Listener unregistered from: {}", id);
				return true;
			}

		}
		//The operation failed
		return false;
	}
	//Remove OnEvent() from addressbook
	void EventSystem::UnregisterAll(Listener* call_back){
		//Check to make sure the event is not already registered
		for (std::multimap<EVENT_TYPE, Listener*>::iterator it = addressbook_.begin(); it != addressbook_.end(); ++it) {
			if (it->second == call_back) {
				addressbook_.erase(it);
			}
		}
		CZ_CORE_INFO("All Listeners unregistered");
		//The listener has no events
	}
		
	//Go through the queue and call the OnEvent() of all associated in addressbook
	void EventSystem::ProcessEvents(){
		//For every item in the queue
		for (auto it : queue_) {
			//Check only in the range of the EVENT_TYPE
			auto range = addressbook_.equal_range(it.EventID);
			//Find all events in the range of the EVENT_TYPE
			for (auto addressbook_it = range.first; addressbook_it != range.second; ++addressbook_it) {
				//Call the OnEvent of the call_back with the EVENT
				addressbook_it->second->OnEvent(it);
			}
		}
	}
	//AddEventSystem:: event to the end of the queue
	void EventSystem::SendEvent(Event event){
		//Add to queue
		queue_.emplace_back(event);
	}

}