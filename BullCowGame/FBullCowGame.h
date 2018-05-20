#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {

	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	EGuessStatus checkGuessValidity(FString) const; // TODO add a meaningful return value
	void reset(); // TODO add a meaningful return value
	

	// counts bulls and cows and increments turn number
	FBullCowCount SubmitValidGuess(FString);

private:
	// set in constructor
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool bGameIsWon;

	bool isIsogram(FString) const;
};