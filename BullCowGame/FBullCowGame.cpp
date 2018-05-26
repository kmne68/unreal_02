#pragma once
#include "FBullCowGame.h"
#include <map>

// to make syntax Unreal friendly
#define TMap std::map 
using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }	// default constructor

int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

int32 FBullCowGame::getMaxTries() const { 
	
	TMap<int32, int32> wordLengthToMaxTries{ {3,5}, {4,6 }, {5,8}, {6,10}, {7,12} };
	return  wordLengthToMaxTries[myHiddenWord.length()]; }

void FBullCowGame::reset() {
	
	const FString HIDDEN_WORD = "planet"; // This must be an isogram
	myHiddenWord = HIDDEN_WORD;
	
	myCurrentTry = 1;
	bGameIsWon = false;
	return;
}


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
		return EGuessStatus::Not_Isogram;
	}
	else if (!isLowercase(guess)) {	
		// if the guess isn't all lowercase return an error		
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != getHiddenWordLength()) {
	// if the guess length is wrong return an error
			return EGuessStatus::Wrong_Length;
	}
	else {
	// otherwise return OK
	return EGuessStatus::OK;	

	}
}