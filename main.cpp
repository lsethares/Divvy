#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
//#include "Station.h";
//#include "Bikes.h";
using namespace std;

//create an ifstream object to read data in from files
ifstream inFile;
//create a string called word to store each element being read in from file
string word;
//create an integer called number to convert each word into
int number;
//create an empty array called dataArray to store data in from the .txt file
string dataArray[0];
//create a vector called dataVector to contain all elements from the .txt file
vector<char*> dataVector;
//create a vector called ClarkAndRandolf to store Bikes in
vector<int> ClarkAndRandolf;

int counter = 0;

struct instruction{
    string checkOutStation;
    string returnStation;
    int checkOutTime;
    int returnTime;
};

vector<instruction> instructionsVector;
instruction trialInstruction;

struct station{
    string name;
    int numberOfBikes;
};

vector<station> vectorOfStations;
station trialStation;

//create a function that creates an instruction from the information in dataVector
void instructionMaker(){
    int i = 0;
    while(i < 417){
        i = i + 4;
        trialInstruction.checkOutStation = dataVector[i];
        trialInstruction.returnStation = dataVector[i+1];
        trialInstruction.checkOutTime = ((atoi(dataVector[i+2]))/100)*60+(atoi(dataVector[i+2])%100);
        trialInstruction.returnTime = ((atoi(dataVector[i+3]))/100)*60+(atoi(dataVector[i+3])%100);
        instructionsVector.push_back(trialInstruction);
        cout << "instruction just added to instructionsVector" << endl;
    }
}

bool contains(vector<station> stationVector, string stationName)
{
    for (int i=0; i<stationVector.size(); i++)
    {
        if (stationVector[i].name == stationName)
        {
            return 0;
        }
    }
    return 1;
}

void stationVectorMaker(){
    int test;
    while (vectorOfStations.size()!=18)
    {
        station firstStation;
        string name = instructionsVector[0].checkOutStation;
        //firstStation.name=instructionsVector[0].checkOutStation;
        firstStation.numberOfBikes=20;
        vectorOfStations.push_back(firstStation);

        for(int i = 1; i <= instructionsVector.size(); i++)
        {
            trialStation.name = instructionsVector[i].checkOutStation;
            trialStation.numberOfBikes = 20;
            if (!contains(vectorOfStations, trialStation.name))
            {
                vectorOfStations.push_back(trialStation);
                cout << trialStation.name << " just added to vectorOfStations" << endl;
                test = 5;
            }
            else
                cout << trialStation.name << " is already in the vectorOfStations" << endl;
        }
    }
}

void redistribute(station fullVector){
    for(int i = 0; i < vectorOfStations.size(); i++){
        if(vectorOfStations[i].numberOfBikes <= 5){
            fullVector.numberOfBikes -= 10;
            vectorOfStations[i].numberOfBikes += 10;
            cout << "10 bikes were just received at " << vectorOfStations[i].name << endl;
        }
    }
}

void clockCounter(){
    int minutes = 0;
    while(minutes < 2880){
        //look at each struct in the instructionsVector[i]
        for(int i = 0; i < instructionsVector.size(); i++){
            //if minutes == instructionVector[i].checkOutTime, look at each vector in the stationsVector
            if(minutes == instructionsVector[i].checkOutTime){
                for(int j = 0; j < vectorOfStations.size(); j++){
                    //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
                    if(instructionsVector[i].checkOutStation == vectorOfStations[j].name){
                        vectorOfStations[j].numberOfBikes -= 1;
                    }
                    if(vectorOfStations[j].numberOfBikes >= 30){
                        cout << "10 bikes were just removed from " << vectorOfStations[j].name << endl;
                        redistribute(vectorOfStations[j]);
                    }
                    else{}
                }
            }
            //else if minutes == instructionsVector[i].returnTime, look at each vector in the stationsVector
            else if(minutes == instructionsVector[i].returnTime){
                for(int j = 0; j < vectorOfStations.size(); j++){
                    //if instructionsVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
                    if(instructionsVector[i].returnStation == vectorOfStations[j].name){
                        vectorOfStations[j].numberOfBikes += 1;
                        if(vectorOfStations[j].numberOfBikes >= 30){
                            cout << "10 bikes were just removed from " << vectorOfStations[j].name << endl;
                            redistribute(vectorOfStations[j]);
                        }
                    }
            }
        }
        //else do nothing
        else{}
        }
        //call the redistribute function which checks if any vector in the stationsVector is full, if one is it takes away 10 bikes and prints a message saying so, then it checks for a vector in the stationsVector that has less than 10 bikes and adds 10 bikes and prints a message saying so
        minutes++;
    }
}

//
//
//vector<instruction> instructionVector;

//create a function called file_to_array that takes in a file name and an empty array and populates it with the data from the file provided
void file_to_array(string arrayProvided[], string fileName){
    inFile.open(fileName);
    //if the file has a problem opening, output an error message
    if(!inFile.is_open())
    {
        cout << "Problem Opening File" << endl;
    }
    //if there's no problem, add all data to an array, printing them to console as they're added to look for mistakes
    while(!inFile.eof()){
        getline(inFile, word, ',');
        cout << word;
        char *cWord = &word[0u];
        dataVector.push_back(cWord);
        counter++;
    }

    inFile.close();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    file_to_array(dataArray, "divvyData.txt");
    instructionMaker();
    stationVectorMaker();
    clockCounter();
    for (int i=0; i<vectorOfStations.size(); i++)
    {
        cout << vectorOfStations[i].name << endl;
    }

//    cout << vectorOfStationVectors[0].name << endl;
//    << " has " << vectorOfStationVectors[0].numberOfBikes << "bikes in it."

    return 0;
}
