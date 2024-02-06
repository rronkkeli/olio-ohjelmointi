#ifndef GROUNDFLOOR_H
#define GROUNDFLOOR_H

#include "floor.h"

class GroundFloor : public Floor {
    Apartment apt1, apt2;
public:
    GroundFloor();
    ~GroundFloor();
    void defineApts() override;
    double calculateConsumption(double) override;
};

#endif // GROUNDFLOOR_H
