#include <string>

#ifndef BIKES_H_
#define BIKES_H_

using namespace std;

class Bikes
{
    private:
        std::string station1;
        std::string station2;
        int checkoutTime;
        int returnTime;
    public:
        Bikes();
        string getFirstStation();
        string getReturnedStation();
        int getCheckoutTime();
        int getReturnTime();
};

#endif // BIKES_H_
