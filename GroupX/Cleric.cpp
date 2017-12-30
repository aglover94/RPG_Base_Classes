/*
* Cleric.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for Cleric class
* Copyright notice
*/

#include "Cleric.h"

//Default Cleric Constructor
Cleric::Cleric()
{
}

//Custom Cleric Constructor
Cleric::Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel)
	:GameCharacter(characterName, health, weightLimit, food, state), pietyLevel_{ pietyLevel } {
}

//Cleric Attack Function
bool Cleric::Attack(GameCharacter & character)
{
	this->SetCharacterState(CharacterState::Idle);

	int chance;
	int equippedArmour = character.GetEquippedArmour();


	if (character.GetState() == CharacterState::Dead || this->GetHealth() <= 20 || this->GetEquippedWeapon() == -1) {
		return false;
	}
	else {
		if (character.GetEquippedArmour() == -1) {
			chance = 80;
		}
		else if (this->GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() > character.GetArmour(equippedArmour).GetDefence()) {
			chance = 60;
		}
		else if (this->GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() < character.GetArmour(equippedArmour).GetDefence()) {
			chance = 20;
		}

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 100);
		int success = dis(gen);

		if (success <= chance) {
			float health = character.GetHealth();
			if (character.GetState() == CharacterState::Sleeping) {
				health = health - health;
				character.SetHealth(health);
			}
			else if (character.GetState() == CharacterState::Dead) {

			}
			else if (character.GetState() == CharacterState::Defending) {
				float amount;
				amount = health / 10;
				health = health - amount;
				character.SetHealth(health);
			}
			else {
				float amount;
				amount = health / 5;
				health = health - amount;
				character.SetHealth(health);
			}

			if (character.GetHealth() == 0) {
				character.SetCharacterState(CharacterState::Dead);
			}

			if (character.GetEquippedArmour() == -1) {

			}
			else {
				int armourHealth = character.GetArmour(equippedArmour).GetArmourHealth();
				int healthDecrease = armourHealth * 10 / 100;
				armourHealth = armourHealth - healthDecrease;
				character.GetArmour(equippedArmour).SetArmourHealth(armourHealth);
				if (armourHealth == 0) {
					character.DropItem(character.GetArmour(equippedArmour));
				}

			}

			return true;
		}
		else {
			if (character.GetEquippedArmour() == -1) {

			}
			else {
				int weaponHealth = this->GetWeapon(GetEquippedWeapon()).GetWeaponHealth();

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_real_distribution<> dis(10, 20);
				int HDecrease = dis(gen);

				int healthDecrease = weaponHealth * HDecrease / 100;

				weaponHealth = weaponHealth - healthDecrease;
				this->GetWeapon(GetEquippedWeapon()).SetWeaponHealth(weaponHealth);

				if (weaponHealth == 0) {
					this->DropItem(this->GetWeapon(GetEquippedWeapon()));
				}
			}
			return false;
		}
	}
}

//Cleric Sleep Function
void Cleric::Sleep()
{
	this->SetCharacterState(CharacterState::Sleeping);

	float health = this->GetHealth();
	if (health < 100.0f) {
		health = health + health * 20 / 100;
		while (health > 100.0f) {
			health--;
		}
	}
	this->SetHealth(health);
}

//Cleric Pray For Function
void Cleric::PrayFor(GameCharacter &character)
{
	int chance = 50;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 100);
	int success = dis(gen);

	float health = character.GetHealth();
	
	if (success <= chance)
	{	
		float amount;
		amount = health / 20;
		amount = amount * pietyLevel_;
		health = health + amount;
		while (health > 100.0f) {
			health--;
		}
		character.SetHealth(health);
	}
	else {

	}
}

//Get and Set Cleric Piety Level
void Cleric::SetPietyLevel(int pietyLevel)
{
	pietyLevel_ = pietyLevel;
}
int Cleric::GetPietyLevel() const
{
	return pietyLevel_;
}
