#pragma once

#include "Chemy\Core.h"

#include "Entity.h"
#include "Component.h"



namespace Chemy {

	class CHEMY_API ECS {
	private:
		// Singleton, deny access to constructors
		// Constructor
		ECS() {}
		// Copy constructor
		ECS(const ECS& rhs) {}
		// Assignment Operator
		ECS& operator=(const ECS& rhs) { return *this; }

		// Make the list of all Components

	public:
		~ECS() { this->Shutdown(); }
		static ECS* Instance() {
			static ECS* Instance = new ECS;
			return Instance;
		}
		void Shutdown();
		bool Init();

	};

}