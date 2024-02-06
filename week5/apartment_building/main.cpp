#include <iostream>
#include "building.h"

using namespace std;

int main() {
    Building *building = new Building();

    cout << "Rakennuksen kulutus on " << building.calculateConsumption(1) << endl;

    delete building;
    return 0;
}
