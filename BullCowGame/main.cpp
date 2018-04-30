#include <iostream>
#include <string>

using namespace std;

void printIntro();
void PlayGame();
string getGuess();
void printGuess(string);

// Entry point for app
int main() {
	
	printIntro();

	PlayGame();

	return 0;
}

void PlayGame()
{
	// loop through number of turns, getting gueses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {

		string guess = getGuess();
		cout << "You guessed " << guess;
		cout << endl;
	}
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
string getGuess() {
	string guess = "";
	cout << "What is your guess?\n";

	std::getline(std::cin, guess);
	// repeat the guess to the player
	return guess;
}


void printGuess(string guess) {

	cout << "You guessed " << guess << "\n";
}
