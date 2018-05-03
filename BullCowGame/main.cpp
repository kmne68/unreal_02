#include <iostream>
#include <string>

void printIntro();
void playGame();
std::string getGuess();
void printGuess(std::string);
bool askToPlayAgain();

// Entry point for app
int main() {
	
	printIntro();

	do {
		playGame();
	} 
	while (askToPlayAgain() == 1);

	return 0;
}

void playGame()
{
	// loop through number of turns, getting gueses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {

		std::string guess = getGuess();
		std::cout << "You guessed " << guess;
		std::cout << std::endl;
	}
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
	std::string guess = "";
	std::cout << "What is your guess?\n";

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