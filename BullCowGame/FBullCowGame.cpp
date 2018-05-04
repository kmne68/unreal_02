#include "FBullCowGame.h"

void FBullCowGame::reset()
{
	return;
}

int FBullCowGame::getMaxTries()
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTry()
{
	return myCurrentTry;
}

bool FBullCowGame::isGameWon()
{
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}
