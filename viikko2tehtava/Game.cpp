#include "Game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Game::Game(int maxnum)
{
    maxNumber = maxnum;
    playerGuess = 0;
    randomNumber = 0;
    numOfGuesses = 0;

    cout << "GAME CONSTRUCTOR: object initialized with "
         << maxNumber << " as a maximum value" << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    cout << "GAME PLAY: starting game" << endl;

    randomNumber = rand() % maxNumber + 1;

    while (true) {
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;
        numOfGuesses = numOfGuesses + 1;

        if (playerGuess < randomNumber) {
            cout << "Your guess is too small" << endl;
        }
        else if (playerGuess > randomNumber) {
            cout << "Your guess is too big" << endl;
        }
        else {
            cout << "Your guess is right = " << randomNumber << endl;
            break;
        }
    }

    cout << "GAME PLAY: game ended" << endl;
}

void Game::printGameResult()
{
    cout << "You guessed the right answer = " << randomNumber
         << " with " << numOfGuesses << " guesses" << endl;
}

