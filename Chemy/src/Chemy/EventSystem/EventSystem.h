#pragma once


#include "Chemy\Core.h"

#include "Event.h"
#include "Listener.h"


namespace Chemy {


	class EventSystem {
	private:
		//Storage for who needs what event
		std::multimap<EVENT_TYPE, Listener*> addressbook_;
		//Event queue
		std::list<Event> queue_;
		// Singleton, deny access to constructors
		// Constructor
		EventSystem() {}
		// Copy constructor
		EventSystem(const EventSystem& rhs) {}
		// Assignment Operator
		EventSystem& operator=(const EventSystem& rhs) { return *this; }
	public:
		~EventSystem() { this->Shutdown(); }
		static EventSystem* Instance() {
			static EventSystem* Instance = new EventSystem;
			return Instance;
		}
		//Clean up
		void Shutdown();
		//Add specific event_type OnEvent() to addressbook_
		bool Register(EVENT_TYPE, Listener*);
		//Remove specific Event_type OnEvent() from addressbook_
		bool Unregister(EVENT_TYPE, Listener*);
		//Remove OnEvent() from addressbook
		void UnregisterAll(Listener*);

		//Go through the queue and call the OnEvent() of all associated in addressbook
		void ProcessEvents();
		//Add event to the end of the queue
		void SendEvent(Event);
		//The systems response to certain events
	};

}