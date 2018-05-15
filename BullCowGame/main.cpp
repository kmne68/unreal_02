/*
This is the console executable that makes use of the BullCow Class. This
acts as the view in an MVC pattern, and is responsible for user interaction.
For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printIntro();
void playGame();
FText getValidGuess();
bool askToPlayAgain();
//void printGuess(FText);

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


	// introduce the game
void printIntro() {
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << "-letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void playGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();

	// loop through number of turns, getting gueses
	for (int32 count = 1; count <= maxTries; count++) { // TODO change from FOR to WHILE loop once we are validating tries
		FText guess = getValidGuess();

		// submit valid guess to the game, receive counts
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cows = " << bullCowCount.Cows << "\n\n";
	}
	// TODO add a game summary
}


// loop continually to get a guess from the user
FText getValidGuess() {

	FText guess = "";
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		int32 currentTry = BCGame.getCurrentTry();		
		std::cout << "Try " << currentTry << ". Enter your guess:\n";
		
		std::getline(std::cin, guess);

		// check status and give feedback
		status = BCGame.checkGuessValidity(guess);
		switch (status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word with no repeating characters.";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word with all letters in lower case.";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (status != EGuessStatus::OK); // continue loop until no errors occur
	return guess;
}


void printGuess(FText guess) {

	std::cout << "You guessed " << guess << "\n";
}


bool askToPlayAgain() {

	std::cout << "Do you want to play again (y/n)";
	FText response = "";
	std::getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');

}