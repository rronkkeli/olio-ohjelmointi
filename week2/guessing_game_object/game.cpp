#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Game::Game(int max) {
    this->maxNumber = max;
}

Game::~Game() {}

void Game::play() {
    srand(time(NULL));
    this->randomNumber = rand() % this->maxNumber + 1;
    this->numOfGuesses = 0;

    this->playerGuess = 0;
    while (this->playerGuess != this->randomNumber) {
        cout << "Anna arvauksesi: ";
        cin >> this->playerGuess;

        if (this->playerGuess > this->randomNumber) {
            cout << "Ajattelemani luku on pienempi.." << endl << "Arvaa uudestaan." << endl;
        } else if (this->playerGuess < this->randomNumber) {
            cout << "Ajattelemani luku on suurempi.." << endl << "Arvaa uudestaan." << endl;
        } else {
            cout << "Arvauksesi on oikein!" << endl;
        }

        this->numOfGuesses++;
    }

    this->printGameResult();
}

void Game::printGameResult() {
    cout << "Arvasit " << this->numOfGuesses << " kertaa." << endl;
}
