#ifndef FLOOR_H
#define FLOOR_H
#include "apartment.h"

class Floor {
    Apartment apt1, apt2, apt3, apt4;
public:
    Floor();
    ~Floor();
    virtual void defineApts();
    virtual double calculateConsumption(double);
};

#endif // FLOOR_H
