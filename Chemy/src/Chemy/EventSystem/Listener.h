#pragma once


#include "Event.h"

namespace Chemy {

	class Listener {

	public:
		virtual void OnEvent(Event) = 0;
	};

}