/*
* GameCharacter.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"


//Default and custom Game Character Constructors
GameCharacter::GameCharacter(){
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state)
	:characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{state} {
	SetEquippedArmour(-1);
	SetEquippedWeapon(-1);
}

//Default Game Character Deconstructor
GameCharacter::~GameCharacter(){
}

//Get and Set Game Character Name Data Member
void GameCharacter::SetCharacterName(std::string characterName)
{
	characterName_ = characterName;
}
std::string GameCharacter::GetCharacterName() const
{
	return characterName_;
}

//Get and Set Game Character Health Data Member
void GameCharacter::SetHealth(float health)
{
	health_ = health;
}
float GameCharacter::GetHealth() const
{
	return health_;
}

//Get and Set Game Character Weight Limit Data Member
void GameCharacter::SetWeightLimit(float weightLimit)
{
	weightLimit_ = weightLimit;
}
float GameCharacter::GetWeightLimit() const
{
	return weightLimit_;
}

//Get and Set Game Character Equipped Weapon
void GameCharacter::SetEquippedWeapon(int equippedWeapon)
{
	equippedWeapon_ = equippedWeapon;
}

int GameCharacter::GetEquippedWeapon()
{
	return equippedWeapon_;
}


//Get and Set Game Character Equipped Armour
void GameCharacter::SetEquippedArmour(int equippedArmour)
{
	equippedArmour_ = equippedArmour;
}

int GameCharacter::GetEquippedArmour()
{
	return equippedArmour_;
}

//Get and Set Game Character Food Data Member
void GameCharacter::SetFood(int food)
{
	food_ = food;
}
int GameCharacter::GetFood() const
{
	return food_;
}

//Set the Game Character State
void GameCharacter::SetCharacterState(CharacterState state)
{
	state_ = state;
}

//Game Character Defend Function
void GameCharacter::Defend(int armour)
{
	state_ = CharacterState::Defending;
	if (armour >= armour_.size()) {
		equippedArmour_ = -1;
	}
	else {
		equippedArmour_ = armour;
	}
}

//Game Character Walk Function
void GameCharacter::Walk()
{
	state_ = CharacterState::Walking;
}

//Game Character Run Function
void GameCharacter::Run()
{
	state_ = CharacterState::Running;
}

//Game Character Get Weapon Function
Weapon& GameCharacter::GetWeapon(int index)
{
	return weapons_[index];
}

//Game Character Get Armour Function
Armour& GameCharacter::GetArmour(int index)
{
	return armour_[index];
}

//Game Character Pickup Weapon Function
bool GameCharacter::PickUpWeapon(Weapon & weapon)
{
	float limit = weapon.GetWeight();

	for (int i = 0; i < weapons_.size(); i++) {
		limit += weapons_[i].GetWeight();
	}

	for (int i = 0; i < armour_.size(); i++) {
		limit += armour_[i].GetWeight();
	}

	if (limit <= weightLimit_) {
		weapons_.push_back(weapon);
		return true;
	}
	else {
		return false;
	}
}

//Game Character Pickup Armour Function
bool GameCharacter::PickUpArmour(Armour & armour)
{
	float limit = armour.GetWeight();

	for (int i = 0; i < weapons_.size(); i++) {
		limit += weapons_[i].GetWeight();
	}

	for (int i = 0; i < armour_.size(); i++) {
		limit += armour_[i].GetWeight();
	}

	if (limit <= weightLimit_) {
		armour_.push_back(armour);
		return true;
	}
	else {
		return false;
	}
}

//Game Character Drop Armour Function
void GameCharacter::DropItem(Armour & item)
{
	for (int i = 0; i < armour_.size(); i++) {
		if (armour_[i].GetItemName() == item.GetItemName()) {
			if (armour_[i].GetItemValue() == item.GetItemValue()) {
				if (armour_[i].GetWeight() == item.GetWeight()) {
					armour_.erase(armour_.begin() + i);
					break;
				}
			}
		}
	}
}

//Game Character Drop Weapon Function
void GameCharacter::DropItem(Weapon & item)
{
	for (int i = 0; i < weapons_.size(); i++) {
		if (weapons_[i].GetItemName() == item.GetItemName()) {
			if (weapons_[i].GetItemValue() == item.GetItemValue()) {
				if (weapons_[i].GetWeight() == item.GetWeight()) {
					weapons_.erase(weapons_.begin() + i);
					break;
				}
			}
		}
	}
}

//Game Character Equip Weapon Function
bool GameCharacter::EquipWeapon(int weapon)
{
	if (weapon >= weapons_.size()) {
		equippedWeapon_ = -1;
	}
	else {
		equippedWeapon_ = weapon;
	}
	return true;
}

//Game Character Get State Function
CharacterState GameCharacter::GetState()
{
	return state_;
}

//Game Character Add Food Function
void GameCharacter::AddFood(int amount)
{
	food_ = food_ + amount;
}

//Game Character Eat Function
void GameCharacter::Eat()
{
	int foodAmount = food_ / 5;
	food_ -= foodAmount;
	if (foodAmount > 0) {
		health_ += 0.25 * foodAmount;
		while (health_ > 100) {
			SetHealth(100.0f);
		}
	}
}
