#pragma once


#include "Chemy\Core.h"





namespace Chemy {


	struct Component {
		//Constructor with name of Component given
		Component(std::string);
		//The current ID of last assigned ComponentMask
		static int currentid_; 
		//Dictionary of Assigned IDs
		static std::map<std::string, int> maskdict_;
		// Name of Component
		const std::string componentname_;
		// ID of Associated Entity
		int entityid_;

		//Mask for the Component
		//const int mask;


		// Below is the Data needed for the structure
	};


	/*
	struct HealthComponent : public Component {
		HealthComponent(int health) : Component("HEALTH"), health_(health){}
		int health_;
	};
	struct ArmourComponent : public Component {
		ArmourComponent(int armour) : Component("ARMOUR"), armour_(armour) {}
		int armour_;
	};
	*/
}