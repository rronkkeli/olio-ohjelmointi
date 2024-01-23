#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"


class ItalianChef : public Chef {
        int flour, water;
    public:
        ItalianChef(string, int, int);
        ~ItalianChef();
        string getName(void);
        void makePasta();
};

#endif // ITALIANCHEF_H
