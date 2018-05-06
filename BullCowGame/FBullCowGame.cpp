#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {

	reset();
}

void FBullCowGame::reset() {

	constexpr int MAX_TRIES = 8;
	int myMaxTries = MAX_TRIES;

	int	myCurrentTry = 1;
	return;
}

int FBullCowGame::getMaxTries() const {
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const {
	return myCurrentTry;
}

bool FBullCowGame::isGameWon() const {
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string) {
	return false;
}
