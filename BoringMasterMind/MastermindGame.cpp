#include "stdafx.h"
#include "MastermindGame.h"


MastermindGame::MastermindGame()
{
	Reset();
	GenarateHiddenNumber(4);
}

void MastermindGame::GenarateHiddenNumber(int DigitNumber)
{
	//Replace hard coded number with generated number
	MyHiddenNumber = "1234";
	return;
}

int MastermindGame::GetCurrentTry() const { return MyCurrentTry; }
int MastermindGame::GetMaxTries() const { return MyMaxTries; }
int MastermindGame::GetHiddenNumberLength() const { return MyHiddenNumber.length(); }

void MastermindGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

GuessStatus MastermindGame::CheckGuessValidity(std::string Guess)
{
	//TODO make actual check
	if (GetHiddenNumberLength() != Guess.length()) {
		return GuessStatus::Wrong_Length;
	} 
	
	return GuessStatus::Ok;
}

//receives a valid guess, increment turn, and returns count
CirclesAndTrianglesCount MastermindGame::SumbitValidGuess(std::string Guess)
{
	MyCurrentTry++;
	CirclesAndTrianglesCount CTCount;

	for (int i = 0; i < MyHiddenNumber.length(); i++)
	{
		if (Guess[i] == MyHiddenNumber[i]) CTCount.Squares++;
		else
		{
			for (int j = 0; j < MyHiddenNumber.length(); j++)
			{
				if (Guess[i] == MyHiddenNumber[j]) CTCount.Circles++;
			}
		}
		
	}
	return CTCount;
}

bool MastermindGame::IsGameWon() const
{
	return false;
}
