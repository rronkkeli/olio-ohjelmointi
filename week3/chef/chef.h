#ifndef CHEF_H
#define CHEF_H
#include <iostream>

using namespace std;

class Chef {
    protected:
        string name;
    public:
        Chef(string);
        ~Chef();
        void makeSalad(void);
        void makeSoup(void);
};

#endif // CHEF_H
