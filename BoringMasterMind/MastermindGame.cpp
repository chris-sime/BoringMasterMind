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
bool MastermindGame::IsGameWon() const { return GameIsWon; }

void MastermindGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	GameIsWon = false;
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
	if (CTCount.Squares == MyHiddenNumber.length()) {
		GameIsWon = true;
	}
	else {
		GameIsWon = false;
	}
	return CTCount;
}


