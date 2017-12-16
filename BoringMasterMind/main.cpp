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
		std::cout << "\tCircles: " << CTCount.Circles << ". Squares: " << CTCount.Squares << std::endl;
		std::cout << std::endl;
	}	
	//TODO: game summary PrintGuess(Guess); // Propably replace with print result from guess
}

//loop until player give a valid Guess
std::string InputValidGuess()
{
	GuessStatus Status = GuessStatus::Invalid_Status;
	std::string Guess = "";

	do {
		std::cout << "Try " << MMGame.GetCurrentTry() << ". Enter your guess: ";
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
void PrintGuess(std::string Guess) {
	std::cout << "\tYour guess is: " << Guess << std::endl;
	return;
}

//ask player if he wants to play again and return his/her answer
bool AskToPlayAgain() {
	std::string Response = "";
	while (Response != "y" || Response != "n" || Response[0] == 'Y' || Response[0] == 'N') {
		std::cout << "Fancy another game? [y/n]:\n";
		std::getline(std::cin, Response);
		if (Response[0] == 'y' || Response[0] == 'Y' ) return true;
		else if (Response[0] == 'n' || Response[0] == 'N') return false;
		else std::cout << "*response not recognized*\n";
	}
	return false;
}

//introduce the game
void PrintIntro()
{
	std::cout << std::endl
		<< "\tWelcome to a boring one-way Mastermind game," << std::endl
		<< "\twhere you play against a computer.\n\n\n" << std::endl
		<< "\tThe computer chooses 4 to 6 unique numbers (0-9)" << std::endl
		<< "\tand you have to guess it!" << std::endl
		<< std::endl;
	return;
}

