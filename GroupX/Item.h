/*
* Item.h
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: header file for Item class
* Copyright notice
*/

#pragma once

#include <string>

class Item
{
private:
	//Private Item Data Members
	std::string itemName_;
	int itemValue_;
	float weight_;

public:
	//Default and Custom Item Constructors
	Item();
	Item(std::string itemName, int value, float weight);

	//Get and Set Item data members
	void SetItemName(std::string itemName);
	std::string GetItemName() const;

	void SetItemValue(int itemValue);
	int GetItemValue() const;

	void SetWeight(float weight);
	float GetWeight() const;
};
