#include <string>
#include "Bikes.h"

#ifndef STATION_H_
#define STATION_H_

class Station
{
    private:
        int totalSpaces;
        int minSpaces;
        //string name;
        Bikes bikeRack[30];
    public:
        Station();
        void returnBike(Bikes b);
        void removeBike(Bikes b);
        int spacesFilled();
        int spacesOpen();
        bool isFull();
};


#endif // STATION_H_
