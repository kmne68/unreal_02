#pragma once
#include <string>

class FBullCowGame {

public:
	void reset(); // TODO add a meaningful return value
	int getMaxTries();
	int getCurrentTry();
	bool isGameWon();
	bool checkGuessValidity(std::string);

private:
	int myCurrentTry = 1;
	int myMaxTries = 5;

};