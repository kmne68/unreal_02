#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:

	FBullCowGame(); // constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	bool isGameWon() const;

	void reset(); // TODO add a meaningful return value
	bool checkGuessValidity(FString); // TODO add a meaningful return value

	// counts bulls and cows and increments turn number
	BullCowCount SubmitGuess(FString);

private:
	// set in constructor
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;

};