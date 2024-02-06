#include "groundfloor.h"
#include <iostream>

using namespace std;

GroundFloor::GroundFloor() {
    *this->apt1 = new Apartment();
    *this->apt2 = new Apartment();
    cout << "Pohjakerros on luotu" << endl;
}

GroundFloor::~GroundFloor() {
    delete this->apt1;
    delete this->apt2;
    cout << "Pohjakerros tuhottiin" << endl;
}

void GroundFloor::defineApts() {
    &this->apt1.setProperties(2, 100);
    &this->apt2.setProperties(2, 100);

    cout << "Pohjakerrokseen m\x84\x84ritettiin 2 asuntoa" << endl;
}

double GroundFloor::calculateConsumption(double p) {
    return &this->apt1.calculateConsumption(p)
                 + &this->apt2.calculateConsumption(p);
}
