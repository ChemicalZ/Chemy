#pragma once



namespace Chemy {
	//Description (message)
	enum EVENT_TYPE {
		MOUSE_DOWN, //Mouse button down (string button)
		MOUSE_UP, //Mouse button release (string button)
		KEYBOARD_DOWN, //Keyboard button pressed (string button)
		KEYBOARD_UP, //Keyboard button released (string button)
		SHUTDOWN //SHUTDOWN INITIATED
	};

	
	struct Event {
		EVENT_TYPE EventID;
		void* msg;
		Event(EVENT_TYPE event, void* message = 0) :
			EventID(event), msg(message) {}
	};


}