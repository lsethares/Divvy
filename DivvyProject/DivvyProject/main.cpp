//
//  main.cpp
//  DivvyProject
//
//  Created by Jason Burkett on 4/22/16.
//  Copyright © 2016 Jason Burkett. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
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
vector<string> dataVector;
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

struct stationVector{
    string name;
    int numberOfBikes;
};

vector<stationVector> vectorOfStationVectors;
stationVector trialStationVector;

//create a function that creates an instruction from the information in dataVector
void instructionMaker(){
    int i = 0;
    while(i < 417){
        i = i + 4;
        trialInstruction.checkOutStation = dataVector[i];
        trialInstruction.returnStation = dataVector[i+1];
        trialInstruction.checkOutTime = ((stoi(dataVector[i+2]))/100)*60+(stoi(dataVector[i+2])%100);
        trialInstruction.returnTime = ((stoi(dataVector[i+3]))/100)*60+(stoi(dataVector[i+3])%100);
        instructionsVector.push_back(trialInstruction);
        cout << "instruction just added to instructionsVector" << endl;
    }
}

void stationVectorMaker(){
    for(int i = 0; i < instructionsVector.size(); i++){
        trialStationVector.name = instructionsVector[i].checkOutStation;
        trialStationVector.numberOfBikes = 15;
        vectorOfStationVectors.push_back(trialStationVector);
        cout << trialStationVector.name << "stationVector just added to vectorOfStationVectors" << endl;
    }
}

void stationChecker(){
    for(int i = 0; i < vectorOfStationVectors.size(); i++){
        for(int j = 0; j < vectorOfStationVectors.size(); j++){
            while(vectorOfStationVectors[i].name == vectorOfStationVectors[j].name){
                cout << vectorOfStationVectors[j].name << " just got erased!" << endl;
                vectorOfStationVectors.erase(vectorOfStationVectors.begin() + j);
                j++;
            }
        }
    }
}

void redistribute(stationVector fullVector){
    for(int i = 0; i < vectorOfStationVectors.size(); i++){
        if(vectorOfStationVectors[i].numberOfBikes <= 5){
            fullVector.numberOfBikes -= 10;
            vectorOfStationVectors[i].numberOfBikes += 10;
            cout << "10 bikes were just received at " << vectorOfStationVectors[i].name << endl;
        }
        else{}
    }
}

void clockCounter(){
    int minutes = 0;
    while(minutes < 2880){
        //look at each struct in the instructionsVector[i]
        for(int i = 0; i < instructionsVector.size(); i++){
            //if minutes == instructionVector[i].checkOutTime, look at each vector in the stationsVector
            if(minutes == instructionsVector[i].checkOutTime){
                for(int j = 0; j < vectorOfStationVectors.size(); j++){
                    //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
                    if(instructionsVector[i].checkOutStation == vectorOfStationVectors[j].name){
                        vectorOfStationVectors[j].numberOfBikes -= 1;
                    }
                    if(vectorOfStationVectors[j].numberOfBikes >= 30){
                        cout << "10 bikes were just removed from " << vectorOfStationVectors[j].name << endl;
                        redistribute(vectorOfStationVectors[j]);
                    }
                    else{}
                }
            }
            //else if minutes == instructionsVector[i].returnTime, look at each vector in the stationsVector
            else if(minutes == instructionsVector[i].returnTime){
                for(int j = 0; j < vectorOfStationVectors.size(); j++){
                    //if instructionsVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
                    if(instructionsVector[i].returnStation == vectorOfStationVectors[j].name){
                        vectorOfStationVectors[j].numberOfBikes += 1;
                        if(vectorOfStationVectors[j].numberOfBikes >= 30){
                            cout << "10 bikes were just removed from " << vectorOfStationVectors[j].name << endl;
                            //call the redistribute function which checks if any vector in the stationsVector is full, if one is it takes away 10 bikes and prints a message saying so, then it checks for a vector in the stationsVector that has less than 10 bikes and adds 10 bikes and prints a message saying so
                            redistribute(vectorOfStationVectors[j]);
                        }
                    }
            }
        }
        //else do nothing
        else{}
        }

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
        dataVector.push_back(word);
        counter++;
    }
    
    inFile.close();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    file_to_array(dataArray, "divvyData.txt");
    instructionMaker();
    stationVectorMaker();
    stationChecker();
    for(int i = 0; i < vectorOfStationVectors.size(); i++){
        cout << vectorOfStationVectors[i].name << " printing the vectorOfStationVectors" << endl;
    }
//    clockCounter();
//    cout << vectorOfStationVectors[0].name << endl;
//    << " has " << vectorOfStationVectors[0].numberOfBikes << "bikes in it."
    
    return 0;
}
