#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
    int maxNumber, playerGuess, randomNumber, numOfGuesses;
    void printGameResult();

public:
    Game(int max);
    ~Game();
    void play();

};

Game::Game(int max) {
    this->maxNumber = max;
}

Game::~Game() {};

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

int main()
{
    while (true) {
        cout << "Haluatko pelata peli\x84 vai lopettaa?" << endl << endl
             << "\t1) Pelaa peli\x84" << endl
             << "\t*) Lopeta ohjelma" << endl << endl
             << "Valintasi: ";
        int c;
        cin >> c;
        if (c == 1) {
            int max;
            cout << "Maksimi: ";
            cin >> max;
            Game game(max);
            game.play();
        } else {
            break;
        }
    }
    return 0;
}
