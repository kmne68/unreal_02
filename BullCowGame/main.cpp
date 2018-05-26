/*
This is the console executable that makes use of the BullCow Class. This
acts as the view in an MVC pattern, and is responsible for user interaction.
For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function prototypes as outside a class
void printIntro();
void playGame();
FText getValidGuess();
bool askToPlayAgain();
void printGameSummary();

// Instantiate a new game which is reused across playes
FBullCowGame BCGame;

// Entry point for app, acting as the View in the MVC pattern
int main() {	
	
	bool bPlayAgain = false;
	do {		
		printIntro();
		playGame();
		bPlayAgain = askToPlayAgain();
	} 
	while (bPlayAgain);

	return 0; // exit the game
}


void printIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "           {  }          ___ " << std::endl;
	std::cout << "          (o  o)      (o o) " << std::endl;
	std::cout << "   /-------\\0/         \\0/-------\\ " << std::endl;
	std::cout << "  /|  BULL  |            | COW    | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// Plays a single game to completion
void playGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();

	// loop through number of turns, getting gueses while the game is not won and tries remain
	while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries) {
		FText guess = getValidGuess();

		// submit valid guess to the game, receive counts
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cows = " << bullCowCount.Cows << "\n\n";
	}
	printGameSummary();
	return;
}


// loop continually to get a guess from the user
FText getValidGuess() {
	FText guess = "";
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		int32 currentTry = BCGame.getCurrentTry();		
		std::cout << "Try " << currentTry << " of " << BCGame.getMaxTries();
		std::cout << ". Enter your guess:\n";
		
		std::getline(std::cin, guess);

		// check status and give feedback
		status = BCGame.checkGuessValidity(guess);
		switch (status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word with no repeating characters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word with all letters in lower case.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (status != EGuessStatus::OK); // continue loop until no errors occur
	return guess;
}


void printGuess(FText guess) {

	std::cout << "You guessed " << guess << "\n";
}


bool askToPlayAgain() {

	std::cout << "Do you want to play again with the same word (y/n)";
	FText response = "";
	std::getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');
}


void printGameSummary() {
	if (BCGame.isGameWon()) {
		std::cout << "Well done! You've won. ";
	}
	else {
		std::cout << "Sorry, you've lost. ";
	}
}
