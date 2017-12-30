/*
* Brawler.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Brawler class
* Copyright notice
*/

#pragma once

#include "GameCharacter.h"
#include <random>

class Brawler : public GameCharacter
{
private:
	//Private Brawler Data Members
	int punchDamage_;
	int strength_;

public:
	//Default and Custom Brawler Constructors
	Brawler();
	Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);

	//Brawler Virtual Attack Function
	virtual bool Attack(GameCharacter &character) override;

	//Virtual Brawler Sleep Function
	virtual void Sleep() override;
	
	//Brawler Brawl Function
	bool Brawl(GameCharacter &character);

	//Get and Set Brawler Data Members
	void SetPunchDamage(int punchDamage);
	int GetPunchDamage() const;

	void SetStrength(int strength);
	int GetStrength() const;

};
