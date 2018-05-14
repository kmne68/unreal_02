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
void printGuess(FText);
bool askToPlayAgain();

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

	return 0;
}

void playGame()
{
	BCGame.reset();
	int32 MaxTries = BCGame.getMaxTries();

	// loop through number of turns, getting gueses
	// TODO change from FOR to WHILE loop once we are validating tries

	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 count = 1; count <= NUMBER_OF_TURNS; count++) {
		FText guess = getValidGuess();

		// submit valid guess to the game, receive counts
		FBullCowCount bullCowCount = BCGame.SubmitGuess(guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cows = " << bullCowCount.Cows << "\n\n";
	}
	// TODO add a game summary
}

// TODO change to make valid guess

void printIntro() {
	// introduce the game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << "-letter I'm thinking of?\n";
	return;
}


// loop continually to get a guess from the user
FText getValidGuess() {

	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		int32 currentTry = BCGame.getCurrentTry();
		
		std::cout << "Try " << currentTry << ". Enter your guess:\n";
		FText guess = "";
		std::getline(std::cin, guess);

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
			return guess;
		}
		std::cout << std::endl;
	} while (status == EGuessStatus::OK); // continue loop until no errors occur
}



void printGuess(FText guess) {

	std::cout << "You guessed " << guess << "\n";
}


bool askToPlayAgain() {

	std::cout << "Do you want to play again (y/n)";
	FText response = "";
	getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');

}