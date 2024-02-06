#include "building.h"
#include <iostream>

using namespace std;

Building::Building() {
    *this->first.defineApts();
    *this->second.defineApts();
    *this->third.defineApts();
    cout << "Kerrostalo luotiin" << endl;
}

Building::~Building() {
    delete this->first;
    delete this->second;
    delete this->third;
    cout << "Rakennus tuhottiin" << endl;
}

double Building::calculateConsumption(double p) {
    return &this->first.calculateConsumption(p)
           + &this->second.calculateConsumption(p)
           + &this->third.calculateConsumption(p);
}
