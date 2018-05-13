#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {

	reset();
}

void FBullCowGame::reset() {

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	int32 myMaxTries = MAX_TRIES;	
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
	for (int32 myWordLength = 0; myWordLength < hiddenWordLength; myWordLength++) {
		// for each letter, compare letter against the hidden word
		for (int32 guessCharacter = 0; guessCharacter < hiddenWordLength; guessCharacter++) {
			// if they match then
			if (guess[guessCharacter] == myHiddenWord[myWordLength]) {
				// increment bulls if they're in the same place
				if (myWordLength == guessCharacter) {
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

 int32 FBullCowGame::getHiddenWordLength() const
 {
	 return myHiddenWord.length();
 }

bool FBullCowGame::isGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const {

	// if guess isn't an isogram
		// return an error
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {	// if the guess isn't all lowercase
		// return an error
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != getHiddenWordLength()) {
	// if the guess length is wrong
		// return an error
			return EGuessStatus::Wrong_Length;
	}
	else {
	// otherwise
		// return OK
	return EGuessStatus::OK;	

	}	// TODO make actual error
}
