#include <iostream>
#include <string>

using namespace std;

void printIntro();
string getAndPrintGuess();

// Entry point for app
int main() {
	
	printIntro();
	getAndPrintGuess();

	return 0;
}

void printIntro() {
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << WORD_LENGTH;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the ";
	cout << "-letter I'm thinking of?\n";
	return;
}


// get a guess from the user
string getAndPrintGuess() {
	string guess = "";
	cout << "What is your guess?\n";

	std::getline(std::cin, guess);
	// repeat the guess to the player
	cout << "You guessed " << guess << "\n";
	cout << "What is your guess?\n";

	std::getline(std::cin, guess);

	cout << "You guessed " << guess << "\n";

	return guess;
}
