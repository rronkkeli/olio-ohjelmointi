#include <iostream>
#include "game.h"

using namespace std;

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
