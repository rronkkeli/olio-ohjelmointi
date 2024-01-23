#include "chef.h"
#include <iostream>

Chef::Chef(string n) {
    this->name = n;
    cout << "Chef " << n << " is preparing to cook.. (constructor)" << endl;
}

Chef::~Chef() {
    cout << "Chef " << this->name << " got fed up with mediocrity and went to cool his brains. (destructor)" << endl;
}

void Chef::makeSalad() {
    cout << "Chef " << this->name << " makes salad." << endl;
}

void Chef::makeSoup() {
    cout << "Chef " << this->name << " makes soup." << endl;
}
