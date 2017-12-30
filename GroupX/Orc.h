/*
* Orc.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Orc class
* Copyright notice
*/

#pragma once

#include "GameCharacter.h"
#include <random>

class Orc : public GameCharacter
{
private:
	//Private Orc Data Members
	int ferociousness_;
	int strength_;

public:
	//Default and Custom Orc Constructors
	Orc();
	Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength);

	//Orc Virtual Attack Function
	virtual bool Attack(GameCharacter &character) override;

	//Orc Virtual Sleep Function
	virtual void Sleep() override;
	
	//Orc Scream Function
	void Scream(GameCharacter &character);

	//Get and Set Orc Data Members
	void SetFerociousness(int ferociousness);
	int GetFerociousness() const;

	void SetStrength(int strength);
	int GetStrength() const;

};
