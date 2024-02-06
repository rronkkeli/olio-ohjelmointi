#include "groundfloor.h"
#include <iostream>

using namespace std;

GroundFloor::GroundFloor() {
    cout << "Pohjakerros on luotu" << endl;
}

GroundFloor::~GroundFloor() {
    cout << "Pohjakerros tuhottiin" << endl;
}

void GroundFloor::defineApts() {
    this->apt1.setProperties(2, 100);
    this->apt2.setProperties(2, 100);

    cout << "Pohjakerrokseen m\x84\x84ritettiin 2 asuntoa" << endl;
}

double GroundFloor::calculateConsumption(double p) {
    return this->apt1.calculateConsumption(p)
                 + this->apt2.calculateConsumption(p);
}
