/*
* Armour.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Armour class
* Copyright notice
*/

#pragma once

#include "Item.h"

enum class ArmourType{Cardboard, Leather, Wood, Iron, Steel};

class Armour : public Item
{
private:
	//Private Armour Data Members
	int defence_;
	int armourHealth_;
	ArmourType armourType_;

public:
	//Default and Custom Armour Constructors
	Armour();
	Armour(std::string armourName, int value, float weight, int armourStrength, int armourHealth, ArmourType armourType);

	//Get and Set Armour Data Members
	void SetDefence(int defence);
	int GetDefence() const;

	void SetArmourHealth(int armourHealth);
	int GetArmourHealth() const;

	void SetArmourType(ArmourType armourtype);
	ArmourType GetType();
};
