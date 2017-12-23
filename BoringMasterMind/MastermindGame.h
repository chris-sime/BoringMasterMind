#pragma once
#include <string>
#include <map>

//Circles when a nubmer exist in the guess
//Square when it's in the right place
struct CirclesAndTrianglesCount
{
	int Circles = 0;
	int Squares = 0;
};

enum Difficulty { Easy, Normal, Hard };


enum GuessStatus {
	Invalid_Status,
	Ok,
	Duplicate_Number_Found,
	Wrong_Length,
	Only_Numbers_Allowed
};


class MastermindGame {
public:

	MastermindGame();
	void GenarateHiddenNumber(); //TODO
	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetHiddenNumberLength() const;
	std::string GetHiddenNumber() const;
	bool IsGameWon() const;
	void SetDifficulty(Difficulty);

	void Reset();
	GuessStatus CheckGuessValidity(std::string);
	CirclesAndTrianglesCount SumbitValidGuess(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
	int MyNumberOfDigits;
	std::string MyHiddenNumber;
	bool GameIsWon;
	Difficulty MyDifficulty;



	bool HasDuplicateDigits(std::string) const;
	bool IsNotNumbers(std::string) const;
	
};