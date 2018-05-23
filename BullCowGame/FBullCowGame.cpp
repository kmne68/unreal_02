#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }


void FBullCowGame::reset() {
	
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";


	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	bGameIsWon = false;
	return;
}


int32 FBullCowGame::getMaxTries() const { return  myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }


bool FBullCowGame::isIsogram(FString guess) const
{
	// treat 0 or 1 letter strings as isograms (return true)
	if (guess.length() <= 1) { return true; }

	// set up the map
	TMap<char, bool> letterSeen;
	// loop through letters in the word
	for (auto letter : guess) {
		letter = tolower(letter);
		if (letterSeen[letter]) {
			return false;
		}
		else {
			letterSeen[letter] = true;
		}

	}

	return true; // for example if /0 is entered
}

bool FBullCowGame::isLowercase(FString guess) const
{
	for (auto letter : guess) {
		if (!islower(letter)) {
			return false;
		}
	}
	return true;
}




// receives a VALID guess and  increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount; // initialized in struct definition
	int32 wordLength = myHiddenWord.length(); // assuming same length as guess

	// loop through all letters in the hidden word
	for (int32 myWordChar = 0; myWordChar < wordLength; myWordChar++) {
		// for each letter, compare letter against the guess
		for (int32 guessCharacter = 0; guessCharacter < wordLength; guessCharacter++) {
			// if they match then
			if (guess[guessCharacter] == myHiddenWord[myWordChar]) {
				// increment bulls if they're in the same place
				if (myWordChar == guessCharacter) {
					bullCowCount.Bulls++;
				}
				else {
					// increment cows if they're not
					bullCowCount.Cows++;
				}
			}
		}
	}
	if (bullCowCount.Bulls == wordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return bullCowCount;
}


EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const {

	// if guess isn't an isogram return an error
	if (!isIsogram(guess)) {
		return EGuessStatus::Not_Isogram;	// TODO write function
	}
	else if (!isLowercase(guess)) {	// if the guess isn't all lowercase
		// return an error
		return EGuessStatus::Not_Lowercase; // TODO write function
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