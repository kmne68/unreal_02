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
FText getGuess();
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
	int MaxTries = BCGame.getMaxTries();

	// loop through number of turns, getting gueses
	// TODO change from FOR to WHILE loop once we are validating tries

	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 count = 1; count <= NUMBER_OF_TURNS; count++) {

		FText guess = getGuess(); // TODO make loop check for valid guesses
		
		EGuessStatus status = BCGame.checkGuessValidity(guess);
		// submit valid guess to game and receive counts
		FBullCowCount bullCowCount = BCGame.SubmitGuess(guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cows = " << bullCowCount.Cows;
		std::cout << std::endl;
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


// get a guess from the user
FText getGuess() {
	
	int32 currentTry = BCGame.getCurrentTry();

	FText guess = "";
	std::cout << "Try " << currentTry << ". Enter your guess:\n";

	std::getline(std::cin, guess);
	// repeat the guess to the player

	return guess;
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