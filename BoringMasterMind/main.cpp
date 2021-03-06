// BoringMasterMind.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "main.h"
#include "MastermindGame.h"

MastermindGame MMGame;
int main()
{
	do {
		system("cls");
		PrintIntro();
		ChooseDifficulty();
		PlayGame();
	} while (AskToPlayAgain());
	return 0; //exit the game
}


void PlayGame()
{
	MMGame.Reset();
	int MaxTries = MMGame.GetMaxTries();

	while (!MMGame.IsGameWon() && (MMGame.GetCurrentTry() <= MaxTries)) {
		std::string Guess = InputValidGuess(); 
		CirclesAndTrianglesCount CTCount = MMGame.SumbitValidGuess(Guess);
		PrintResults(CTCount);
		std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}

//Print Visual representetion for your result instead of text
void PrintResults(CirclesAndTrianglesCount CTCount) {
	char Square = 254; //ascii code for square
	char Circle = 79; //ascii code for circle

	std::cout << "\t";
	for (int i = 0; i < CTCount.Squares; i++)
	{
		std::cout << Square << " ";
	}
	for (int i = 0; i < CTCount.Circles; i++)
	{
		std::cout << Circle << " ";
	}
	std::cout << std::endl;
}

//loop until player give a valid Guess
std::string InputValidGuess()
{
	GuessStatus Status = GuessStatus::Invalid_Status;
	std::string Guess = "";

	do {
		std::cout << "Try " << MMGame.GetCurrentTry() << " of "<< MMGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = MMGame.CheckGuessValidity(Guess);
		switch (Status) {
		case GuessStatus::Wrong_Length:
			std::cout << "Expected " << MMGame.GetHiddenNumberLength() << " digits. You typed " << Guess.length() << ".\n\n";
			break;
		case GuessStatus::Duplicate_Number_Found:
			std::cout << "Please enter a word without repeating numbers!\n\n";
			break;
		case GuessStatus::Only_Numbers_Allowed:
			std::cout << "Please use only numbers!\n\n";
			break;
		default:
			GuessStatus::Ok;
			break;
		}
	} while (Status != GuessStatus::Ok);

	return Guess;
}

//prints the guess
void PrintGameSummary() {
	if (MMGame.IsGameWon()) std::cout << "\tWell done mate! You found the correct number!\n\n";
	else std::cout << "\tBetter luck next time pal! Make sure to play again in order to became Mastermind\n\n";
	return;
}

//ask player if he wants to play again and return his/her answer
bool AskToPlayAgain() {
	std::string Response = "";
	while (true) {
		std::cout << "Fancy another game? [y/n]:\n";
		std::getline(std::cin, Response);
		if (Response[0] == 'y' || Response[0] == 'Y' ) return true;
		else if (Response[0] == 'n' || Response[0] == 'N') return false;
		else std::cout << "*response not recognized*\n";
	}
	return false;
}

//Let the player set the difficulty of the game
void ChooseDifficulty() {
	std::cout << "Choose difficulty\n"
		"\t\"Easy\": (20 Tries, 4 Digit number)\n"
		"\t\"Normal\": (15 Tries, 5 Digit number)\n"
		"\t\"Hard\": (10 Tries, 6 Digit number)\n";
	std::string Response = "";
	;
	while (true) {
		std::cout << "Select: ";
		std::getline(std::cin, Response);
		Response[0] = tolower(Response[0]);
		if (Response[0] == 'e') {
			MMGame.SetDifficulty(Difficulty::Easy);
			std::cout << "_____________________________________\n\n";
			return;
		}
		else if (Response[0] == 'n') {
			MMGame.SetDifficulty(Difficulty::Normal);
			std::cout << "_____________________________________\n\n";
			return;
		}
		else if (Response[0] == 'h') {
			MMGame.SetDifficulty(Difficulty::Hard);
			std::cout << "_____________________________________\n\n";
			return;
		}
		else std::cout << "*responce not recognized*\n";
	}
	
}

//introduce the game
void PrintIntro()
{
	//std::cout << std::endl <<
	//	"\tWelcome to a boring one-way Mastermind game,\n"
	//	"\twhere you play against a computer.\n\n"
	//	"\tThe computer chooses 4 to 6 unique numbers (0-9)\n"
	//	"\tand you have to guess it!\n\n"
	//	<< std::endl;
	std::cout << "\n\n"
		"   ||                                                                            ||\n"
		"   ||      @@@@@  @@@   @@@  @@@@ @@@  @@@@     @@@@@  @@@  @@   @  @@@@         ||\n"
		"   ||      @ @ @  @ @   @     @@  @    @  @     @ @ @   @   @ @  @  @   @        ||\n"
		"   ||      @ @ @  @@@    @    @@  @@@  @@@      @ @ @   @   @  @ @  @    @       ||\n"
		"   ||      @ @ @  @ @     @   @@  @    @  @     @ @ @   @   @   @@  @   @        ||\n"
		"   ||      @ @ @  @ @  @@@@   @@  @@@  @   @    @ @ @  @@@  @    @  @@@@         ||\n"
		"   ||                                                                            ||\n"
		"   ||     Guess the correct number. You get a square if you find the correct     ||\n"
		"   ||     digit in the correct position. You get a cirlce if you find a digit    ||\n"
		"   ||     but not in the correct position.  Good Luck!                           ||\n"
		"\n\n\n";
	return;
}

//TODO: add help/how to play info ingame (via menu maybe?)
