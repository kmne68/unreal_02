#include "FBullCowGame.h"

void FBullCowGame::reset()
{
	return;
}

int FBullCowGame::getMaxTries() const
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const
{
	return myCurrentTry;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}
