// Craps Game
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Functions
void welcomeMessage();
void mainMenu();
int rollDice();
int comeOutRoll();
int pointRoll();
void betMenu();
int passComeBet();

// Variables
int playerMoney = 500;
int playerBet;

int main()
{
	welcomeMessage();
	mainMenu();

	return 0;
}

void welcomeMessage()
{
	std::cout << "Welcome to JD's Craps table!" << std::endl << std::endl;
	std::cin.get();
}

void mainMenu()
{
	int mainMenuChoice;
	bool repeat = false;


	std::cout << " ___________________ " << std::endl;
	std::cout << "|     Main Menu     |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "| 1. Place a bet    |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "| 2. Roll the dice  |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "| 3. Information    |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "| 4. Quit           |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "Menu Selection: ";
	std::cin >> mainMenuChoice;
	std::cout << std::endl;


	do
	{
		switch (mainMenuChoice)
		{
		case 1:
			betMenu();
			repeat = false;
			break;

		case 2:
			std::cout << std::endl;
			comeOutRoll();
			repeat = false;
			break;

		case 3:
			std::cout << "Information Placeholder\n";
			repeat = false;
			break;

		case 4:
			std::cout << "Thanks for playing!\n";
			repeat = false;
			break;

		default:
			std::cout << "Please enter a valid entry (1-4)\n";
			std::cout << "Menu Selection: ";
			std::cin >> mainMenuChoice;
			std::cout << std::endl;
			repeat = true;
			break;
		}
	} while (repeat == true);


}

void betMenu()
{
	int betMenuChoice;
	bool repeat = false;


	std::cout << " __________________________ " << std::endl;
	std::cout << "|       Betting Menu       |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| 1. Pass/Come             |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| 2. Don't Pass/Don't come |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| 3. Information           |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| 4. Return                |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "Menu Selection: ";
	std::cin >> betMenuChoice;
	std::cout << std::endl;

	do
	{
		switch (betMenuChoice)
		{
		case 1:
			passComeBet();
			repeat = false;
			break;

		case 2:
			std::cout << "Don't Pass\Don't Come Placeholder\n";
			repeat = false;
			break;

		case 3:
			std::cout << "Information Placeholder\n";
			repeat = false;
			break;

		case 4:
			mainMenu();
			repeat = false;
			break;

		default:
			std::cout << "Please enter a valid entry (1-4)\n";
			std::cout << "Menu Selection: ";
			std::cin >> betMenuChoice;
			std::cout << std::endl;
			repeat = true;
			break;
		}
	} while (repeat == true);

}

int rollDice()
{
	int die1;
	int die2;
	int sum;

	srand(time(0));

	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	sum = die1 + die2;

	return sum;
}

int comeOutRoll()
{
	int comeOutSum;

	if (playerBet <= 0)
	{
		std::cout << "You must place a bet to roll\n";
		std::cout << std::endl;
		mainMenu();
	}
	
	rollDice();
	comeOutSum = rollDice();

	if (comeOutSum == 7 || comeOutSum == 11)
	{
		std::cout << comeOutSum << std::endl;
		std::cout << "You win!\n" << std::endl;

		playerMoney = playerMoney + playerBet;
		
		std::cout << "You now have " << playerMoney;
		std::cout << std::endl;

		playerBet = 0;

		mainMenu();
	}

	else if (comeOutSum == 2 || comeOutSum == 3 || comeOutSum == 12)
	{
		std::cout << comeOutSum << std::endl;
		std::cout << "You lose!\n" << std::endl;

		playerMoney = playerMoney - playerBet;
		
		std::cout << "You now have " << playerMoney;
		std::cout << std::endl;

		playerBet = 0;

		mainMenu();
	}

	else
	{
		std::cout << "The point is: " << rollDice() << std::endl;
		pointRoll();
	}
	return rollDice();
}

int pointRoll()
{
	int point = rollDice();
	int pointRollSum;
	bool reRoll = false;
	int i;

	std::cout << "Roll again" << std::endl;
	std::cin.ignore();
	std::cin.get();
	std::cout << std::endl;

	do
	{
		rollDice();
		pointRollSum = rollDice();

		if (pointRollSum == 7)
		{
			std::cout << pointRollSum << std::endl;
			std::cout << "You lose!\n" << std::endl;

			playerMoney = playerMoney - playerBet;
			
			std::cout << "You now have " << playerMoney;
			
			playerBet = 0;

			reRoll = false;
			mainMenu();
		}

		else if (pointRollSum == point)
		{
			std::cout << pointRollSum << std::endl;
			std::cout << "You win!\n" << std::endl;

			playerMoney = playerMoney + playerBet;
	
			std::cout << "You now have " << playerMoney;
			std::cout << std::endl;

			playerBet = 0;
			
			reRoll = false;
			mainMenu();
		}

		else
		{
			std::cout << pointRollSum << std::endl;
			std::cout << "Roll again" << std::endl;
			std::cin.get();
			std::cout << std::endl;

			reRoll = true;
		}
	} while (reRoll == true);


	return rollDice();
}

int passComeBet()
{
		
	std::cout << "You have $" << playerMoney << std::endl;
	std::cout << "How much would you like to bet? " << std::endl;
	std::cin >> playerBet;
	std::cout << std::endl;
	mainMenu();

	return playerBet;

}