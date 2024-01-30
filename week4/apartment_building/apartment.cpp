#include "apartment.h"
#include <iostream>

using namespace std;

Apartment::Apartment() {
    cout << "Asunto luotiin" << endl;
}

Apartment::~Apartment() {
    cout << "Asunto tuhottiin" << endl;
}

void Apartment::setProperties(int o, int a) {
    this->occupants = o;
    this->area = a;
    cout << "Asuntoon m\x84\x84ritetty asukkaita " << o << " hl\x94\x84 ja neli\x94t\x84 " << a << endl;
}

double Apartment::calculateConsumption(double p) {
    return p * this->occupants * this->area;
}
