/*
* Weapon.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Weapon class
* Copyright notice
*/

#pragma once

#include "Item.h"

class Weapon : public Item
{
private:
	//Private Weapon Data Members
	int weaponHitStrength_;
	int weaponHealth_;

public:
	//Default and Custom Weapon Constructors
	Weapon();
	Weapon(std::string weaponName, int value, float weight, int hitStrength, int health);

	//Get and Set Weapon Data Members
	void SetWeaponHitStrength(int weaponHitStrength);
	int GetWeaponHitStrength() const;

	void SetWeaponHealth(int weaponHealth);
	int GetWeaponHealth() const;
};
