// BoringMasterMind.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "main.h"


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
	constexpr int NUMBER_OF_TRIES = 5;
	for (int i = 0; i < NUMBER_OF_TRIES; i++) {
		PrintGuess(InputGuess());
		std::cout << std::endl;
	}
}

//get a player to guess a number
std::string InputGuess()
{
	std::string Guess = "";
	std::cout << "\tEnter your guess: ";
	std::getline(std::cin, Guess);
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
		<< "\tand you have to guess it!" << std::endl;
	return;
}

