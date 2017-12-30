/*
* Weapon.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for Weapon class
* Copyright notice
*/

#include "Weapon.h"

//Default Weapon Constructor
Weapon::Weapon()
{
}

//Custom Weapon Constructor
Weapon::Weapon(std::string weaponName, int value, float weight, int hitStrength, int health)
	:Item(weaponName, value, weight), weaponHitStrength_{ hitStrength }, weaponHealth_{ health } {
}

//Get and Set Weapon Hit Strength
void Weapon::SetWeaponHitStrength(int weaponHitStrength)
{
	weaponHitStrength_ = weaponHitStrength;
}
int Weapon::GetWeaponHitStrength() const
{
	return weaponHitStrength_;
}

//Get and Set Weapon Health
void Weapon::SetWeaponHealth(int weaponHealth)
{
	weaponHealth_ = weaponHealth;
}
int Weapon::GetWeaponHealth() const
{
	return weaponHealth_;
}