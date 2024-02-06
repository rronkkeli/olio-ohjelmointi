#ifndef APARTMENT_H
#define APARTMENT_H


class Apartment {
    int *occupants, *area;
public:
    Apartment();
    ~Apartment();
    void setProperties(int, int);
    double calculateConsumption(double);
};

#endif // APARTMENT_H
