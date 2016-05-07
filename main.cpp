#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
//#include "Station.h";
//#include "Bikes.h";
using namespace std;

//create an empty array called dataArray to store data in from the .txt file
string dataArray[500];
//create a vector called dataVector to contain all elements from the .txt file
vector<string> dataVector;

//struct to hold data that is read in
struct instruction
{
    string checkOutStation;
    string returnStation;
    int checkOutTime;
    int returnTime;
};

vector<instruction> instructionsVector;
instruction trialInstruction;

//struct to store station data
struct station
{
    string name;
    int numberOfBikes;
};

vector<station> vectorOfStations;
station trialStation;

//create a function that creates an instruction from the information in dataVector
void instructionMaker()
{
    int i = 0;
    while(i < 417)
    {
        i = i + 4;
        char *checkOut = &dataVector[i+2][0u];
        char* returnT = &dataVector[i+3][0u];
        trialInstruction.checkOutStation = dataVector[i];
        trialInstruction.returnStation = dataVector[i+1];
        trialInstruction.checkOutTime = ((atoi(checkOut))/100)*60+(atoi(checkOut)%100);
        trialInstruction.returnTime = ((atoi(returnT))/100)*60+(atoi(returnT)%100);
        instructionsVector.push_back(trialInstruction);
    }
}

void stationVectorMaker()
{   //for each item in instructionsVector
    for(int i = 0; i < instructionsVector.size(); i++)
    {
        trialStation.name = instructionsVector[i].checkOutStation;
        trialStation.numberOfBikes = 15;
        //add the modified struct to the vectorOfstationStructs
        bool is_in = false;
        //check if station can be found in vectorOfStations
        for(int j = 0; j < vectorOfStations.size(); j++)
        {
            if(vectorOfStations[j].name == trialStation.name)
            {
                is_in=true;
                j=vectorOfStations.size();
            }
        }

        //if station was not found - add to vectorOfStations
        if(!is_in)
        {
            vectorOfStations.push_back(trialStation);
            //cout << trialStation.name << "stationStruct just added to vectorOfstationStructs" << endl;
        }
    }
}

//check-out data
void checkOutEvents(int minutes)
{
    //look at each struct in the instructionsVector[i]
    for(int i = 0; i < instructionsVector.size(); i++)
    {
        //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
        if(minutes == instructionsVector[i].checkOutTime)
        {
            cout << instructionsVector[i].checkOutStation << " should have a bike checked out at " << minutes << " minutes." << endl;
            for(int j = 0; j < vectorOfStations.size(); j++)
            {
                //if instructionVector[i].checkOutStation == stationsVector[j], remove a bike
                if(instructionsVector[i].checkOutStation.compare(vectorOfStations[j].name) == 0)
                {
                    vectorOfStations[j].numberOfBikes = vectorOfStations[j].numberOfBikes - 1;

                    //redistribute bikes if the station has 10 or fewer bikes
                    if (vectorOfStations[j].numberOfBikes <= 10)
                    {
                        //move ten bikes to vectorOfStiaions[j]
                        vectorOfStations[j].numberOfBikes += 10;
                        cout << "This station is running low, so ten bikes have been moved to " << vectorOfStations[j].name << endl;
                        //remove ten bikes from a random station
                        int random = rand()%10 + 9;
                        vectorOfStations[random].numberOfBikes -= 10;
                    }
                    cout << vectorOfStations[j].name << " has " << vectorOfStations[j].numberOfBikes << " left.\n" << endl;
                }
            }
        }
    }
}

//return data
void returnEvents(int minutes)
{
    for(int i = 0; i < instructionsVector.size(); i++)
    {
        if(minutes == instructionsVector[i].returnTime)
        {
            cout << instructionsVector[i].returnStation << " should have a bike returned at " << minutes << " minutes." << endl;
            for(int j = 0; j < vectorOfStations.size(); j++)
            {
                //if instructionVector[i].returnStation == stationsVector[j], add a bike
                if(instructionsVector[i].returnStation.compare(vectorOfStations[j].name) == 0)
                {
                    vectorOfStations[j].numberOfBikes = vectorOfStations[j].numberOfBikes + 1;

                    //redistribute bikes if the station is full
                    if (vectorOfStations[j].numberOfBikes >= 30)
                    {
                        //move ten bikes to vectorOfStiaions[j]
                        vectorOfStations[j].numberOfBikes -= 10;
                        cout << "This station is full, so ten bikes have been moved from " << vectorOfStations[j].name << endl;
                        //add ten bikes to a random station
                        int random = rand()%10 + 9;
                        vectorOfStations[random].numberOfBikes += 10;
                    }
                    cout << vectorOfStations[j].name << " has " << vectorOfStations[j].numberOfBikes << " left.\n" << endl;
                }
            }
        }
    }
}

void clockCounter()
{
    int minutes = 0;
    while(minutes < 1435)
    {
        checkOutEvents(minutes); //anaylise all check-out data
        returnEvents(minutes);
        minutes++;
    }
}



//takes in a file name and an empty array and populates it with the data from the file provided
void file_to_array(vector<string> vectorProvided, string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    //if the file has a problem opening, output an error message
    if(!inFile.is_open())
    {
        cout << "Problem Opening File" << endl;
    }
    //if there's no problem, add all data to an array
    while(!inFile.eof())
    {
        string word;
        getline(inFile, word, ',');
        dataVector.push_back(word);
    }
    inFile.close();
}

int main(int argc, const char * argv[])
{
    // insert code here...
    file_to_array(dataVector, "divvyData.txt");
    instructionMaker();
    stationVectorMaker();
    clockCounter();
    cout << "At the end of the day the stations are populated as follows: " << endl;
    for (int i =0; i<vectorOfStations.size(); i++)
        cout << vectorOfStations[i].name << "\t" << vectorOfStations[i].numberOfBikes << endl;

    return 0;
}
