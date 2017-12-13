#pragma once
#include <string>

class MastermindGame {
public:

	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool CheckGuess(std::string); //TODO: make better return type later
	bool IsGameWon();

private:
	int MyCurrentTry;
	int MyMaxTries;
};