/*
* BlackWitch.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for BlackWitch class
* Copyright notice
*/

#include "BlackWitch.h"

//Default Black Witch Constructor
BlackWitch::BlackWitch()
{
}

//Custom Black Witch Constructor
BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower)
	:GameCharacter(characterName, health, weightLimit, food, state), magicProficiency_{ magicProficiency }, darkPower_{ darkPower } {
}

//Black Witch Attack Function
bool BlackWitch::Attack(GameCharacter & character)
{
	this->SetCharacterState(CharacterState::Idle);

	int chance;
	int equippedArmour = character.GetEquippedArmour();


	if (character.GetState() == CharacterState::Dead || this->GetHealth() <= 20 || this->GetEquippedWeapon() == -1) {
		return false;
	}
	else {
		if  (character.GetEquippedArmour() == -1) {
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
			int percentIncrease;
			if (darkPower_ == 100) {
				percentIncrease = 20;
			}
			else {
				percentIncrease = 0;
			}

			if (character.GetState() == CharacterState::Sleeping) {
				health = health - health;
				character.SetHealth(health);
			}
			else if (character.GetState() == CharacterState::Dead) {

			}
			else if (character.GetState() == CharacterState::Defending) {
				float amount;
				int percent = 10 + percentIncrease;
				amount = health*percent / 100;
				health = health - amount;
				character.SetHealth(health);
			}
			else {
				float amount;
				int percent = 20 + percentIncrease;
				amount = health*percent / 100;
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

//Black Witch Sleep Function
void BlackWitch::Sleep()
{
	this->SetCharacterState(CharacterState::Sleeping);

	float health = this->GetHealth();
	if (health < 100.0f) {
		health = health + health * 15 / 100;
		while (health > 100.0f) {
			health--;
		}
	}
	this->SetHealth(health);
}

//Black Witch Bewitch Function
void BlackWitch::Bewitch(GameCharacter & character)
{
	int chance = 10;
	int CIncrease = 5 * magicProficiency_;
	chance = chance + CIncrease;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 100);
	int success = dis(gen);

	if (success <= chance) {
		character.SetCharacterState(CharacterState::Sleeping);
	}
	else {

	}
}

//Get and Set Black Witch Magic Proficiency
void BlackWitch::SetMagicProficiency(int magicProficiency)
{
	magicProficiency_ = magicProficiency;
}
int BlackWitch::GetMagicProficiency() const
{
	return magicProficiency_;
}

//Get and Set Black Witch Dark Power
void BlackWitch::SetDarkPower(int darkPower)
{
	darkPower_ = darkPower;
}
int BlackWitch::GetDarkPower() const
{
	return darkPower_;
}
