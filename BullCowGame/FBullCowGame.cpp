#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {

	reset();
}

void FBullCowGame::reset() {

	constexpr int32 MAX_TRIES = 8;
	int32 myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	myHiddenWord = HIDDEN_WORD;
	int32	myCurrentTry = 1;
	return;
}


// receives a VALID guess and  increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	// increment the turn number
	myCurrentTry++;

	// set up the return variable
	FBullCowCount bullCowCount; // initialized in struct definition

	// loop through all letters in the guess
	int32 hiddenWordLength = myHiddenWord.length();
	for (int32 i = 0; i < hiddenWordLength; i++) {
		// for each letter, compare letter against the hidden word
		for (int32 j = 0; j < hiddenWordLength; j++) {		
			// if they match then
			if (guess[i] == myHiddenWord[i]) {
				// increment bulls if they're in the same place
				if (i == j) {
					bullCowCount.Bulls++;
				}
				else {
					// increment cows if they're not
					bullCowCount.Cows++;
				}
			}
		}
	}

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
