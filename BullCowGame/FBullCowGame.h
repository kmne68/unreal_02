#pragma once
#include <string>

class FBullCowGame {

public:

	FBullCowGame(); // constructor

	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;

	void reset(); // TODO add a meaningful return value
	bool checkGuessValidity(std::string); // TODO add a meaningful return value
	// provide a method to count bulls and cows and increment turn number

private:
	// set in constructor
	int myCurrentTry;
	int myMaxTries;

};