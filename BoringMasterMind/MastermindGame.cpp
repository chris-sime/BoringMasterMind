#include "stdafx.h"
#include "MastermindGame.h"
#include <iostream>
#include <time.h>

MastermindGame::MastermindGame()
{
	Reset();
}

//TODO: Find a better way to genarate numbers with non repeated digits
void MastermindGame::GenarateHiddenNumber()
{
	std::map<char, bool> DigitsSeen;
	srand(time(NULL));
	do {
		MyHiddenNumber = "";
		for (int i = 0; i < MyNumberOfDigits; i++)
		{
			MyHiddenNumber.append(std::to_string(rand() % 10));
		}
	} while (HasDuplicateDigits(MyHiddenNumber));
	
	return;
}

int MastermindGame::GetCurrentTry() const { return MyCurrentTry; }
int MastermindGame::GetMaxTries() const { return MyMaxTries; }
int MastermindGame::GetHiddenNumberLength() const { return MyHiddenNumber.length(); }
std::string MastermindGame::GetHiddenNumber() const { return MyHiddenNumber; }

bool MastermindGame::IsGameWon() const { return GameIsWon; }
bool MastermindGame::HasDuplicateDigits(std::string Guess) const
{
	std::map<char, bool> DigitSeen;
	for (auto Digit : Guess) {
		if (DigitSeen[Digit]) return true;
		else DigitSeen[Digit] = true;
	}
	return false;
}
bool MastermindGame::IsNotNumbers(std::string Guess) const
{
	for (auto d : Guess) {
		if (!isdigit(d)) return true;
	}
	return false;
}
void MastermindGame::SetDifficulty(Difficulty dif) {
	switch (dif)
	{
	case Easy:
		MyMaxTries = 20;
		MyNumberOfDigits = 4;
		break;
	case Normal:
		MyMaxTries = 15;
		MyNumberOfDigits = 5;
		break;
	case Hard:
		MyMaxTries = 10;
		MyNumberOfDigits = 6;
		break;
	default:
		MyMaxTries = 20;
		MyNumberOfDigits = 4;
		break;
	}
}
void MastermindGame::Reset()
{
	GenarateHiddenNumber();
	MyCurrentTry = 1;
	GameIsWon = false;
	return;
}

GuessStatus MastermindGame::CheckGuessValidity(std::string Guess)
{
	//TODO make actual check
	if (HasDuplicateDigits(Guess)) return GuessStatus::Duplicate_Number_Found;
	else if (GetHiddenNumberLength() != Guess.length()) return GuessStatus::Wrong_Length;
	else if (IsNotNumbers(Guess)) return GuessStatus::Only_Numbers_Allowed;
	else return GuessStatus::Ok;
}

//receives a valid guess, increment turn, and returns count
CirclesAndTrianglesCount MastermindGame::SumbitValidGuess(std::string Guess)
{
	MyCurrentTry++;
	CirclesAndTrianglesCount CTCount;

	for (int i = 0; i < (int)MyHiddenNumber.length(); i++)
	{
		if (Guess[i] == MyHiddenNumber[i]) CTCount.Squares++;
		else
		{
			for (int j = 0; j < (int)MyHiddenNumber.length(); j++)
			{
				if (Guess[i] == MyHiddenNumber[j]) CTCount.Circles++;
			}
		}
	}
	if (CTCount.Squares == MyHiddenNumber.length()) {
		GameIsWon = true;
	}
	else {
		GameIsWon = false;
	}
	return CTCount;
}


