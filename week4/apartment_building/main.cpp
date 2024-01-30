#include <iostream>
#include "building.h"

using namespace std;

int main() {
    Building building;

    cout << "Rakennuksen kulutus on " << building.calculateConsumption(1) << endl;
    return 0;
}
