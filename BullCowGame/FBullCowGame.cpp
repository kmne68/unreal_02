#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {

	reset();
}

void FBullCowGame::reset() {

	constexpr int32 MAX_TRIES = 8;
	int32 myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;
	int32	myCurrentTry = 1;
	return;
}


// receives a VALID guess and  increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	myCurrentTry++;

	// set up the return variable
	BullCowCount bullCowCount; // initialized in struct definition

	// loop through all letters in the guess
	// for each letter, compare letter against the hidden word
	return bullCowCount;
}

int32 FBullCowGame::getMaxTries() const {
	return myMaxTries;
}

 int32 FBullCowGame::getCurrentTry() const {
	return myCurrentTry;
}

bool FBullCowGame::isGameWon() const {
	return false;
}

bool FBullCowGame::checkGuessValidity(FString) {
	return false;
}
