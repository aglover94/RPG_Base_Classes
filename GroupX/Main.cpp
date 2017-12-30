/*
* Main.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Main source file for assignment two
* Copyright notice
*/

#include <iostream>
#include <random>

#include "GameCharacter.h"

#include "BlackWitch.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"

using namespace std;

int main() {

	BlackWitch B1{ "Witch", 70.0f, 55.0f, 20, CharacterState::Idle, 10, 10 };

	Brawler Br1{ "Brawler", 70.0f, 150.0f, 50, CharacterState::Idle, 60, 20};

	Cleric C1{ "Cleric", 70.0f, 150.0f, 1, CharacterState::Idle, 2 };

	Orc O1{ "Orc", 70.0f, 150.0f, 20, CharacterState::Idle, 10, 10 };

	Weapon W1{ "Sword", 10, 10.5f, 60, 10 };
	Weapon W2{ "Sword", 10, 10.5f, 60, 100 };
	Armour A1{ "Armour", 10, 10.5f, 50, 100, ArmourType::Leather };
	Armour A2{ "Armour2", 10, 10.5f, 50, 100, ArmourType::Leather };

	B1.PickUpWeapon(W1);
	B1.EquipWeapon(0);
	C1.PickUpArmour(A1);
	C1.PickUpArmour(A2);
	C1.Defend(0);

	B1.Attack(C1);

	return 0;
}
