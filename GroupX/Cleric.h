/*
* Cleric.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Cleric class
* Copyright notice
*/

#pragma once

#include "GameCharacter.h"
#include <random>

class Cleric : public GameCharacter
{
private:
	//Private Cleric Data Member
	int pietyLevel_;

public:
	//Default and Custom Cleric Constructors
	Cleric();
	Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel);

	//Cleric Virtual Attack function
	virtual bool Attack(GameCharacter &character) override;

	//Virtual Cleric Sleep Function
	virtual void Sleep() override;

	//Cleric Pray For Function
	void PrayFor(GameCharacter &character);

	//Get and Set Cleric Data Member
	void SetPietyLevel(int pietyLevel);
	int GetPietyLevel() const;

};
