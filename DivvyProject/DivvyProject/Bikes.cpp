#include <iostream>
#include "Bikes.h"

using namespace std;

Bikes::Bikes()
{
    station1 = "";
    station2 = "";
    checkoutTime = 0;
    returnTime = 0;
}

string Bikes::getFirstStation()
{
    return station1;
}

string Bikes::getReturnedStation()
{
    return station2;
}

int Bikes::getCheckoutTime()
{
    return checkoutTime;
}

int Bikes::getReturnTime()
{
    return returnTime;
}
