#include <iostream>
#include <string>

using namespace std;

int main() {

	constexpr int WORD_LENGTH = 5;

	string guess = "";

	// introduce the game
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the ";
	cout << WORD_LENGTH;
	cout << "-letter I'm thinking of?\n";

	// get a guess from the user
	cout << "What is your guess?\n";

	std::getline(std::cin, guess);
	// repeat the guess to the player
	cout << "You guessed " << guess << "\n";


	cout << "What is your guess?\n";

	std::getline(std::cin, guess);

	cout << "You guessed " << guess << "\n";

	return 0;
}