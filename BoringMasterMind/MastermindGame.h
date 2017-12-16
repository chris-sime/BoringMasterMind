#pragma once
#include <string>

struct CirclesAndTrianglesCount
{
	int Circles = 0;
	int Squares = 0;
};

enum difficulty { Easy, Normal, Hard };

enum GuessStatus {
	Invalid_Status,
	Ok,
	Duplicate_Number_Found,
	Wrong_Length,
	Only_Numbers_Allowed
};
//Circles when a nubmer exist in the guess
//Square when it's in the right place

class MastermindGame {
public:

	MastermindGame();
	void GenarateHiddenNumber(int); //TODO
	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetHiddenNumberLength() const;
	bool IsGameWon() const;

	void Reset();
	GuessStatus CheckGuessValidity(std::string);
	CirclesAndTrianglesCount SumbitValidGuess(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
	std::string MyHiddenNumber;
};