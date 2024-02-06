#ifndef BUILDING_H
#define BUILDING_H
#include "groundfloor.h"
#include "floor.h"

class Building {
    GroundFloor *first;
    Floor *second, *third;
public:
    Building();
    ~Building();
    double calculateConsumption(double);
};

#endif // BUILDING_H
