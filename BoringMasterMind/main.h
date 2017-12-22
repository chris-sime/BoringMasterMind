#pragma once
#include "MastermindGame.h"

void PrintIntro();
int main();
void PlayGame();
void PrintResults(CirclesAndTrianglesCount);
std::string InputValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();
void ChooseDifficulty();