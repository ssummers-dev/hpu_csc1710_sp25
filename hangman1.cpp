Example Solution (hangman.cpp):

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidGuess(string input) {
    return input.length() == 1 && isalpha(input[0]);
}

int main() {
    string word = "hangman";
    string display(word.length(), '_');
    string guessedLetters = "";
    int wrongGuesses = 0;
    const int maxGuesses = 5;
    string input;

    cout << "Welcome to Hangman!" << endl;

    while (display != word && wrongGuesses < maxGuesses) {
        cout << "The word is: ";
        for (char c : display) cout << c << ' ';
        cout << "\nGuess a letter: ";
        cin >> input;

        if (!isValidGuess(input)) {
            cout << "Invalid input. Please enter a single letter.\n";
            continue;
        }

        char guess = tolower(input[0]);
        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter.\n";
            continue;
        }

        guessedLetters += guess;

        size_t pos = word.find(guess);
        if (pos != string::npos) {
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) display[i] = guess;
            }
            cout << "Correct!\n";
        } else {
            ++wrongGuesses;
            cout << "Wrong! You have " << wrongGuesses << "/" << maxGuesses << " incorrect guesses.\n";
        }
    }

    if (display == word) {
        cout << "You won! The word was: " << word << endl;
    } else {
        cout << "You lost! The word was: " << word << endl;
    }

    return 0;
}

