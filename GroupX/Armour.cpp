/*
* Armour.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for Armour class
* Copyright notice
*/

#include "Armour.h"

//Default Armour Constructor
Armour::Armour()
{
}

//Custom Armour Constructor
Armour::Armour(std::string armourName, int value, float weight, int armourStrength, int armourHealth, ArmourType armourType)
	:Item(armourName, value, weight), defence_{ armourStrength }, armourHealth_{ armourHealth }, armourType_{ armourType } {
}

//Get and Set Armour Defence
void Armour::SetDefence(int defence)
{
	defence_ = defence;
}
int Armour::GetDefence() const
{
	return defence_;
}

//Get and Set Armour Health
void Armour::SetArmourHealth(int armourHealth)
{
	armourHealth_ = armourHealth;
}
int Armour::GetArmourHealth() const
{
	return armourHealth_;
}

//Get and Set Armour Type
void Armour::SetArmourType(ArmourType armourtype)
{
	armourType_ = armourtype;
}
ArmourType Armour::GetType()
{
	return armourType_;
}
