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
string dataArray[500];
//create a vector called dataVector to contain all elements from the .txt file
vector<string> dataVector;
//create a vector called ClarkAndRandolf to store Bikes in
//vector<int> ClarkAndRandolf;

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
        char *checkOut = &dataVector[i+2][0u];
        char* returnT = &dataVector[i+3][0u];
        trialInstruction.checkOutStation = dataVector[i];
        trialInstruction.returnStation = dataVector[i+1];
        trialInstruction.checkOutTime = ((atoi(checkOut))/100)*60+(atoi(checkOut)%100);
        trialInstruction.returnTime = ((atoi(returnT))/100)*60+(atoi(returnT)%100);
        instructionsVector.push_back(trialInstruction);
        //cout << "instruction just added to instructionsVector" << endl;
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
/*
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
*/

void stationVectorMaker(){
    for(int i = 0; i < instructionsVector.size(); i++){
        trialStation.name = instructionsVector[i].checkOutStation;
        trialStation.numberOfBikes = 15;
        //add the modified struct to the vectorOfstationStructs
        bool is_in = false;
        for(int j = 0; j < vectorOfStations.size(); j++)
        {
            if(vectorOfStations[j].name == trialStation.name)
            {
                is_in=true;
                j=vectorOfStations.size();
            }
        }

        if(!is_in)
        {
            vectorOfStations.push_back(trialStation);
            //cout << trialStation.name << "stationStruct just added to vectorOfstationStructs" << endl;
        }
        else{
            //cout << trialStation.name << "already exists!" << endl;
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
void checkOutEvents(int minutes){
    //look at each struct in the instructionsVector[i]
    for(int i = 0; i < instructionsVector.size(); i++){
        //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
        if(minutes == instructionsVector[i].checkOutTime){
            cout << instructionsVector[i].checkOutStation << " should have a bike checked out at " << minutes << " minutes.";
            for(int j = 0; j < vectorOfStations.size(); j++){
                //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
                if(instructionsVector[i].checkOutStation.compare(vectorOfStations[j].name) == 0){
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfStations[j].name << endl;
                    //cout << vectorOfStations[j].name << " just had " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfStations[j].numberOfBikes = vectorOfStations[j].numberOfBikes - 1;
                    //cout << vectorOfStations[j].name << " now has " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    if(vectorOfStations[j].numberOfBikes < 0){
                        cout << vectorOfStations[j].name << " STATION IS NOW EMPTY: \n" << endl;
                        //                        redistribute(vectorOfstationStructs[j]);
                        //                            j = vectorOfstationStructs.size();
                    }
                    else{
                        cout << vectorOfStations[j].name << " has " << vectorOfStations[j].numberOfBikes << " left.\n" << endl;
                        //                            j = vectorOfstationStructs.size();
                    }
                }
                else{
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " <<vectorOfStations[j].name << endl;
                    //                        j = vectorOfstationStructs.size();
                }
            }
        }
    }
}

void returnEvents(int minutes){
    for(int i = 0; i < instructionsVector.size(); i++){
        if(minutes == instructionsVector[i].returnTime){
            cout << instructionsVector[i].returnStation << " should have a bike returned at " << minutes << " minutes." <<endl;
            for(int j = 0; j < vectorOfStations.size(); j++){
                //if instructionVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
                if(instructionsVector[i].returnStation.compare(vectorOfStations[j].name) == 0){
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfStations[j].name << endl;
                    //cout << vectorOfStations[j].name << " just had " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfStations[j].numberOfBikes = vectorOfStations[j].numberOfBikes + 1;
                    //cout << vectorOfStations[j].name << " now has " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    if(vectorOfStations[j].numberOfBikes < 0){
                        cout << vectorOfStations[j].name << " STATION IS NOW EMPTY: \n" << endl;
                        //                        redistribute(vectorOfstationStructs[j]);
                        //                            j = vectorOfstationStructs.size();
                    }
                    else{
                        cout << vectorOfStations[j].name << " has " << vectorOfStations[j].numberOfBikes << " left.\n" << endl;
                        //                            j = vectorOfstationStructs.size();
                    }
                }
                else{
                    //cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfStations[j].name << endl;
                    //                        j = vectorOfstationStructs.size();
                }
            }
        }
    }
}

void clockCounter(){
    int minutes = 0;
    while(minutes < 1435){
        checkOutEvents(minutes);
        returnEvents(minutes);
        minutes++;
    }
}


//
//
//vector<instruction> instructionVector;

//create a function called file_to_array that takes in a file name and an empty array and populates it with the data from the file provided
void file_to_array(vector<string> vectorProvided, string fileName){
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
        dataVector.push_back(word);
//        counter++;
//        cout << counter << endl;
    }
    cout << " \n" << endl;
    inFile.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    file_to_array(dataVector, "divvyData.txt");
    instructionMaker();
    stationVectorMaker();
    clockCounter();
//    cout << vectorOfStationVectors[0].name << endl;
//    << " has " << vectorOfStationVectors[0].numberOfBikes << "bikes in it."

    return 0;
}
