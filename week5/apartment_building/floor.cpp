#include "floor.h"
#include <iostream>

using namespace std;

Floor::Floor() {
    *this->apt1 = new Apartment();
    *this->apt2 = new Apartment();
    *this->apt3 = new Apartment();
    *this->apt4 = new Apartment();
    cout << "Kerros on luotu" << endl;
}

Floor::~Floor() {
    delete this->apt1;
    delete this->apt2;
    delete this->apt3;
    delete this->apt4;
    cout << "Kerros tuhottiin" << endl;
}

void Floor::defineApts() {
    &this->apt1.setProperties(2, 100);
    &this->apt2.setProperties(2, 100);
    &this->apt3.setProperties(2, 100);
    &this->apt4.setProperties(2, 100);

    cout << "Kerrokseen m\x84\x84ritettiin 4 asuntoa" << endl;
}

double Floor::calculateConsumption(double p) {
    return &this->apt1.calculateConsumption(p)
                 + &this->apt2.calculateConsumption(p)
                 + &this->apt3.calculateConsumption(p)
                 + &this->apt4.calculateConsumption(p);
}
