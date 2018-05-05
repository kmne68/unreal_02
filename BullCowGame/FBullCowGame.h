#pragma once
#include <string>

class FBullCowGame {

public:
	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;

	void reset(); // TODO add a meaningful return value
	bool checkGuessValidity(std::string);

private:
	int myCurrentTry = 1;
	int myMaxTries = 5;

};