#include "italianchef.h"

ItalianChef::ItalianChef(string name, int water, int flour): Chef(name) {
    this->water = water;
    this->flour = flour;
}

ItalianChef::~ItalianChef() {}

string ItalianChef::getName() {
    return this->name;
}

void ItalianChef::makePasta() {
    cout << "Chef " << this->getName() << " makes pasta with his secret recipe." << endl
         << "Chef " << this->getName() << " uses " << this->flour << " grams of flour." << endl
         << "Chef " << this->getName() << " uses " << this->water << " grams of water." << endl;
}
