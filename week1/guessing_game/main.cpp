#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessing_game(int range_max);

int main() {
    while (true) {
        int max;
        cout << "Give a maximum number for random numbers. Exit by giving 0." << endl << "Give number: ";
        cin >> max;
        if (max > 0) {
            guessing_game(max);
        } else {
            break;
        }
    }

    cout << "Exiting.." << endl;

    return 0;
}

void guessing_game(int range_max) {
    srand(time(NULL));
    int random = (rand() % range_max) + 1;
    int guess;
    int guesses = 0;
    cout << "Guess the number I'm thinking." << endl;

    while (true) {
        cout << "Your guess: ";
        cin >> guess;
        if (guess == random) {
            cout << "Your guess was correct!" << endl;
            break;
        } else if (guess < random) {
            cout << "Too small!" << endl;
        } else {
            cout << "Too big!" << endl;
        }
        guesses++;
    }

    cout << "You guessed " << guesses + 1 << " times." << endl;
    cout << "You may play again or exit." << endl;
}
