#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharacterCreation
{		
	/*TEST_CLASS(CharacterManagement)
	{
	public:
		TEST_METHOD(TestCharacterConstructor)
		{
			//Test that the character constructor works correctly
			std::string expectedName{ "John" };
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 10, 60 };

			//Act
			std::string characterName = brawler.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}

		TEST_METHOD(TestAddFood)
		{
			//Test that the amount of food is increased by the correct amount

			int expectedFood{ 26 }, actualFood;
			Brawler brawler{ "Jim", 100.0f, 120.0f, 20, CharacterState::Idle, 60, 80 };

			//Act
			brawler.AddFood(6);
			actualFood = brawler.GetFood();

			//Assert
			Assert::AreEqual(expectedFood, actualFood);
		}

		TEST_METHOD(TestEatConsumesFood)
		{
			//Test that the correct number of food is consumed

			int expectedFood{ 16 }, actualFood;
			Brawler brawler{ "Jim", 100.0f, 120.0f, 20, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualFood = brawler.GetFood();

			//Assert
			Assert::AreEqual(expectedFood, actualFood);
		}

		TEST_METHOD(TestEatIncreasesHealth)
		{
			//Test that the eat function increases the character health

			float expectedHealth{ 52.5f }, actualHealth; 
			Brawler brawler{ "Jim", 50.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

		TEST_METHOD(TestHealthCapped)
		{
			//Test that health is capped at 100 when the eat function is called

			float expectedHealth{ 100.0f }, actualHealth; 
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

		TEST_METHOD(TestSleepHealthWorks)
		{
			//Test that the sleep function works correctly

			float expectedHealth{ 60.0f }, actualHealth;
			Brawler brawler{ "Jim", 50.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Sleep();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

		TEST_METHOD(TestSleepHealthCapped)
		{
			//Test that the health is capped at 100 for the sleep function

			float expectedHealth{ 100.0f }, actualHealth;
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Sleep();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}
	};
}

namespace ItemCreation
{
	TEST_CLASS(ItemManagement)
	{
	public:
		TEST_METHOD(TestItemConstructor)
		{
			// Test that item constructor works correctly

			std::string expectedName{ "Spear" };
			Weapon Spear1{ "Spear", 40, 25, 50, 100 };

			//Act
			std::string itemName = Spear1.GetItemName();

			//Assert
			Assert::AreEqual(expectedName, itemName);
		}
	};
}

namespace InventoryTests
{
	TEST_CLASS(InventoryManagement)
	{
	public:

		TEST_METHOD(TestEquippedWInital)
		{
			//Test that equipped weapon is -1 at initialisation

			int expectedEquipped{ -1 }, actualEquipped;
			Brawler brawler{ "Jim", 100.0f, 120.0f, 20, CharacterState::Idle, 60, 80 };
			
			//Act
			actualEquipped = brawler.GetEquippedWeapon();

			//Assert
			Assert::AreEqual(expectedEquipped, actualEquipped);
		}

		TEST_METHOD(TestEquippedAInital)
		{
			//Test that equipped armour is -1 at initialisation

			int expectedEquipped{ -1 }, actualEquipped;
			Brawler brawler{ "Jim", 100.0f, 120.0f, 20, CharacterState::Idle, 60, 80 };

			//Act
			actualEquipped = brawler.GetEquippedArmour();

			//Assert
			Assert::AreEqual(expectedEquipped, actualEquipped);
		}

		TEST_METHOD(TestAddWeaponWeightFalse)
		{
			//Test that the armour doesn't get added as it exceeds weightlimit

			bool addItem;
			Brawler brawler{ "John", 100, 30, 60, CharacterState::Idle, 10, 60 };
			Weapon Spear1{ "Spear", 40, 25, 50, 100 };
			Weapon Spear2{ "Pike", 50, 25, 50, 100 };

			//Act
			addItem = brawler.PickUpWeapon(Spear1);
			addItem = brawler.PickUpWeapon(Spear2);

			//Assert
			Assert::IsFalse(addItem);
		}

		TEST_METHOD(TestAddWeaponWeightTrue)
		{
			//Test that the armour gets added as it doesn't exceed weightlimit

			bool addItem;
			Brawler brawler{ "John", 100, 100, 60, CharacterState::Idle, 10, 60 };
			Weapon Spear1{ "Spear", 40, 25, 50, 100 };
			Weapon Spear2{ "Pike", 50, 25, 50, 100 };

			//Act
			addItem = brawler.PickUpWeapon(Spear1);
			addItem = brawler.PickUpWeapon(Spear2);

			//Assert
			Assert::IsTrue(addItem);
		}

		TEST_METHOD(TestAddArmourWeightFalse)
		{
			//Test that the armour doesn't get added as it exceeds weightlimit

			bool addItem;
			Brawler brawler{ "John", 100, 30, 60, CharacterState::Idle, 10, 60 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };
			Armour Chest2{ "Chest", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			addItem = brawler.PickUpArmour(Chest1);
			addItem = brawler.PickUpArmour(Chest2);

			//Assert
			Assert::IsFalse(addItem);
		}

		TEST_METHOD(TestAddArmourWeightTrue)
		{
			//Test that the armour gets added as it doesn't exceed weightlimit

			bool addItem;
			Brawler brawler{ "John", 100, 100, 60, CharacterState::Idle, 10, 60 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };
			Armour Chest2{ "Chest", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			addItem = brawler.PickUpArmour(Chest1);
			addItem = brawler.PickUpArmour(Chest2);

			//Assert
			Assert::IsTrue(addItem);
		}

		TEST_METHOD(TestGetWeapon)
		{
			//Test get weapon

			Brawler brawler{ "John", 100, 100, 60, CharacterState::Idle, 10, 60 };
			Weapon Spear1{ "Spear", 40, 25, 50, 100 };
			Weapon Spear2{ "Pike", 50, 25, 50, 100 };
			Weapon Bow{ "Jackal", 50, 25, 50, 100 };
			std::string expectedName{ "Jackal" };

			//Act
			brawler.PickUpWeapon(Spear1);
			brawler.PickUpWeapon(Spear2);
			brawler.PickUpWeapon(Bow);

			Weapon tempWeapon = brawler.GetWeapon(2);
			std::string weaponName = tempWeapon.GetItemName();

			//Assert
			Assert::AreEqual(expectedName, weaponName);
		}

		TEST_METHOD(TestGetArmour)
		{
			//Test get armour 

			Brawler brawler{ "John", 100, 100, 60, CharacterState::Idle, 10, 60 };
			Armour Chest{ "Chest", 40, 25, 50, 100, ArmourType::Cardboard };
			Armour Legs{ "Legs", 50, 25, 50, 100, ArmourType::Cardboard };
			Armour Arms{ "Jackal", 50, 25, 50, 100, ArmourType::Cardboard };
			std::string expectedName{ "Legs" };
			
			//Act
			brawler.PickUpArmour(Chest);
			brawler.PickUpArmour(Legs);
			brawler.PickUpArmour(Arms);

			Armour tempArmour = brawler.GetArmour(1);
			std::string armourName = tempArmour.GetItemName();

			//Assert
			Assert::AreEqual(expectedName, armourName);
		}

		TEST_METHOD(TestDropWeapon)
		{
			//Test that the correct weapon item is taken out of the character inventory

			std::string expectedWeaponName{ "spear" };
			Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Weapon bow{ "bow", 15, 25, 100, 3 };
			Weapon spear2{ "spear", 10, 2, 70, 2 };

			//Act
			brawler.PickUpWeapon(spear1);
			brawler.PickUpWeapon(bow);
			brawler.PickUpWeapon(spear2);

			brawler.DropItem(spear2);
			Weapon tempWeapon = brawler.GetWeapon(0);
			std::string actualWeaponName = tempWeapon.GetItemName();

			//Assert
			Assert::AreEqual(expectedWeaponName, actualWeaponName);
		}

		TEST_METHOD(TestDropArmour)
		{
			//Test that the correct armour item is taken out of the character inventory

			std::string expectedArmourName{ "Cardboard suit of armour" };
			Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
			Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
			Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::Cardboard };
			Armour glove1{ "Leather glove", 1, 0.23f, 1, 100, ArmourType::Leather };
			Armour suit{ "Cardboard suit of armour", 10, 2.0f, 15, 100, ArmourType::Cardboard };
			Armour glove2{ "Leather glove", 1, 0.2f, 1, 75, ArmourType::Leather };

			//Act
			brawler.PickUpArmour(shield);
			brawler.PickUpArmour(hat);
			brawler.PickUpArmour(glove1);
			brawler.PickUpArmour(suit);
			brawler.PickUpArmour(glove2);

			brawler.DropItem(glove1);
			Armour tempArmour = brawler.GetArmour(2);
			std::string actualArmourName = tempArmour.GetItemName();

			//Assert
			Assert::AreEqual(expectedArmourName, actualArmourName);
		}
	};
}

namespace ConflictTests
{
	TEST_CLASS(Conflict)
	{
	public:
		TEST_METHOD(TestArmourStaysEmpty)
		{
			//Test that when passing in an invalid armour value, that the equipped armour value remains -1

			int expected{ -1 }, actualIndex;
			Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Defend(0);
			actualIndex = brawler.GetEquippedArmour();

			//Assert
			Assert::AreEqual(expected, actualIndex);
		}

		TEST_METHOD(TestEquipWeaponEqualsWeapon)
		{
			//Test that when a valid weapon is passed in, that equipped weapon value is that value
			//indicating a weapon is equipped

			int expected{ 0 }, actual;

			Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };

			//Act
			brawler.PickUpWeapon(spear1);
			brawler.EquipWeapon(0);
			actual = brawler.GetEquippedWeapon();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestEquipWeaponDoesNotEqualWeapon)
		{
			//Test that when an invalid weapon is passed in, that equipped weapon value is -1
			//indicating no weapon equipped

			int expected{ -1 }, actual;

			Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };

			//Act
			brawler.PickUpWeapon(spear1);
			brawler.EquipWeapon(2);
			actual = brawler.GetEquippedWeapon();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		//Due to the chance aspect of the attack, brawl, scream, bewitch and prayfor functions 
		//sometimes the tests will fail, sometimes they will pass based on the outcomes within the functions themselves.
		
		TEST_METHOD(TestTrueAttack)
		{
			//Test for a return value of true, indicating a successful attack

			bool expected{ true }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Idle, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			brawler.PickUpWeapon(spear1);
			blackwitch.PickUpArmour(Chest1);
			brawler.EquipWeapon(0);
			blackwitch.Defend(0);

			actual = brawler.Attack(blackwitch);

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestBrawlAttack)
		{
			//Test the brawl function returns true upon a successful attack

			bool expected{ true }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Idle, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			brawler.PickUpWeapon(spear1);
			blackwitch.PickUpArmour(Chest1);

			actual = brawler.Brawl(blackwitch);

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestfalseAttack)
		{
			//Test for an unsuccessful attack

			bool expected{ false }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Idle, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			blackwitch.PickUpWeapon(spear1);
			brawler.PickUpArmour(Chest1);

			actual = blackwitch.Attack(brawler);

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestAttackHealthIdle)
		{
			//Test that 20% of health is taken off character after a successful attack when idle

			float expected{ 80.0f }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Idle, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			brawler.PickUpWeapon(spear1);
			blackwitch.PickUpArmour(Chest1);
			brawler.EquipWeapon(0);

			brawler.Attack(blackwitch);
			actual = blackwitch.GetHealth();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestAttackHealthSleeping)
		{
			//Test that if a character is sleeping that their health is fully depleted

			float expected{ 0.0f }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Sleeping, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			brawler.PickUpWeapon(spear1);
			blackwitch.PickUpArmour(Chest1);
			brawler.EquipWeapon(0);

			brawler.Attack(blackwitch);
			actual = blackwitch.GetHealth();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestAttackHealthDead)
		{
			//Test that nothing happens to a character that is dead

			float expected{ 100.0f }, actual;
			Brawler brawler{ "John", 100, 150, 60, CharacterState::Idle, 20, 6 };
			BlackWitch blackwitch{ "Jane", 100, 150, 60, CharacterState::Dead, 5, 20 };
			Weapon spear1{ "spear", 15, 25, 100, 6 };
			Armour Chest1{ "Chest Plate", 100, 25, 50, 100, ArmourType::Leather };

			//Act
			brawler.PickUpWeapon(spear1);
			blackwitch.PickUpArmour(Chest1);
			brawler.EquipWeapon(0);

			brawler.Attack(blackwitch);
			actual = blackwitch.GetHealth();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestPrayFor)
		{
			//Test that the bewitch function adds value to health

			float expected{77.0f}, actual;
			Cleric cleric{ "Jack", 70, 150, 60, CharacterState::Idle, 2 };

			//Act
			cleric.PrayFor(cleric);
			actual = cleric.GetHealth();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestPrayForHealthCapped)
		{
			//Test that the bewitch function adds value to health

			float expected{ 100.0f }, actual;
			Cleric cleric{ "Jack", 100, 150, 60, CharacterState::Idle, 2 };

			//Act
			cleric.PrayFor(cleric);
			actual = cleric.GetHealth();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		/*TEST_METHOD(TestBewitch) 
		{
			//Test that the bewitch function changes character state to sleeping

			int expectedState{ 2 }, actualState;
			Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };
			BlackWitch blackwitch{ "Jane", 100, 120, 50, CharacterState::Idle, 7, 80 };

			//Act
			blackwitch.Bewitch(brawler);
			actualState = brawler.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}

		TEST_METHOD(TestScream)
		{
			//Test that the scream function changes character state to running

			int expectedState{ 1 }, actualState;
			Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };
			Orc orc{ "John", 100, 120, 50, CharacterState::Idle, 10, 80 };

			//Act
			orc.Scream(brawler);
			actualState = brawler.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}
	};*/
}