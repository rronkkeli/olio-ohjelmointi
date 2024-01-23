#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main() {
    Chef gordon("Gordon Ramsay");
    ItalianChef anthony("Anthony Bourdain", 20, 200);

    gordon.makeSalad();
    gordon.makeSoup();

    anthony.makeSalad();
    anthony.makePasta();
    anthony.makeSoup();

    return 0;
}
