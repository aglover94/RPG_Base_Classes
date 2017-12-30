/*
* Item.cpp
*
* Version information v1.0
* Authors: William Glover B00718680
* Date: 21/12/2017
* Description: Implementation for Item class
* Copyright notice
*/

#include "Item.h"

//Default Item Constructor
Item::Item()
{
}

//Custom Item Constructor
Item::Item(std::string itemName, int value, float weight)
	:itemName_{ itemName }, itemValue_{ value }, weight_{ weight } {
}

//Get and Set Item Name
void Item::SetItemName(std::string itemName)
{
	itemName_ = itemName;
}
std::string Item::GetItemName() const
{
	return itemName_;
}

//Get and Set Item Value
void Item::SetItemValue(int itemValue)
{
	itemValue_ = itemValue;
}
int Item::GetItemValue() const
{
	return itemValue_;
}

//Get and Set Item Weight
void Item::SetWeight(float weight)
{
	weight_ = weight;
}
float Item::GetWeight() const
{
	return weight_;
}
