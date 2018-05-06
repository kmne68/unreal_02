#include <iostream>
#include <string>
#include "FBullCowGame.h"

void printIntro();
void playGame();
std::string getGuess();
void printGuess(std::string);
bool askToPlayAgain();

FBullCowGame BCGame;

// Entry point for app
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

	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {

		std::string guess = getGuess(); // TODO make loop check for valid guesses
		
		// submit valid guess to game
		// print number of bulls and cows
		std::cout << "You guessed " << guess;
		std::cout << std::endl;
	}
	// TODO add a game summary
}

void printIntro() {
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << WORD_LENGTH;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the ";
	std::cout << "-letter I'm thinking of?\n";
	return;
}


// get a guess from the user
std::string getGuess() {
	
	int currentTry = BCGame.getCurrentTry();

	std::string guess = "";
	std::cout << "Try " << currentTry << ". Enter your guess:\n";

	std::getline(std::cin, guess);
	// repeat the guess to the player

	return guess;
}



void printGuess(std::string guess) {

	std::cout << "You guessed " << guess << "\n";
}


bool askToPlayAgain() {

	std::cout << "Do you want to play again (y/n)";
	std::string response = "";
	getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');

}