#pragma once
#include <string>

class FBullCowGame {

public:
	void reset(); // TODO add a meaningful return value
	int getMaxTries();

private:
	int myCurrentTry();
	int myMaxTries();
	int getCurrentTry();
	bool isGameWon();
	bool checkGuessValidity(std::
		string);

};