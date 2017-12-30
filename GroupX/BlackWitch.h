/*
* BlackWitch.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for BlackWitch class
* Copyright notice
*/

#pragma once

#include "GameCharacter.h"
#include <random>

class BlackWitch : public GameCharacter
{
private:
	//Private Black Witch Data Members
	int magicProficiency_;
	int darkPower_;

public:
	//Default and Custom Black Witch Constructors
	BlackWitch();
	BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower);

	//Black Witch Virtual Attack Function
	virtual bool Attack(GameCharacter &character) override;

	//Virtual Black Witch Sleep Function
	virtual void Sleep() override;

	//Black Witch Bewitch Function
	void Bewitch(GameCharacter &character);

	//Get and Set Black Witch Data Members
	void SetMagicProficiency(int magicProficiency);
	int GetMagicProficiency() const;

	void SetDarkPower(int darkPower);
	int GetDarkPower() const;

};
