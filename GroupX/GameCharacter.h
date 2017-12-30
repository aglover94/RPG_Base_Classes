/*
* GameCharacter.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for GameCharacter class
* Copyright notice
*/

#pragma once

#include <string>
#include <vector>
#include "Weapon.h"
#include "Armour.h"

enum class CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead };

class GameCharacter
{
private:
	//Private Game Character Data Members
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_;
	int equippedArmour_;
	std::vector<Weapon> weapons_;
	std::vector<Armour> armour_;
	int food_;
	CharacterState state_;

public:
	//Default Game Character Constructor, Custom Constructor and Deconstructor
	GameCharacter();
	GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state);
	~GameCharacter();

	//Get and Set Game Character Data Members
	void SetCharacterName(std::string characterName);
	std::string GetCharacterName() const;

	void SetHealth(float health);
	float GetHealth() const;

	void SetWeightLimit(float weightLimit);
	float GetWeightLimit() const;

	void SetEquippedWeapon(int equippedWeapon);
	int GetEquippedWeapon();

	void SetEquippedArmour(int equippedArmour);
	int GetEquippedArmour();

	void SetFood(int food);
	int GetFood() const;

	void SetCharacterState(CharacterState state);

	//Virtual Game Character Attack Function
	virtual bool Attack(GameCharacter &character) = 0;

	//Game Character Defend Function
	void Defend(int armour);

	//Game Character Walk Function
	void Walk();

	//Game Character Run Function
	void Run();

	//Virtual Game Character Sleep Function
	virtual void Sleep() = 0;

	//Game Character Get Weapon Function
	Weapon& GetWeapon(int index);

	//Game Character Get Armour Function
	Armour& GetArmour(int index);

	//Game Character Pickup Weapon Function
	bool PickUpWeapon(Weapon &weapon);

	//Game Character Pickup Armour Function
	bool PickUpArmour(Armour &armour);

	//Game Character Drop Item Armour Function
	void DropItem(Armour &item);

	//Game Character Drop Item Weapon Function
	void DropItem(Weapon &item);

	//Game Character Equip Weapon Function
	bool EquipWeapon(int weapon);

	//Game Character Get Character State Function
	CharacterState GetState();

	//Game Character Add Food Function
	void AddFood(int amount);

	//Game Character Eat Function
	void Eat();
};

