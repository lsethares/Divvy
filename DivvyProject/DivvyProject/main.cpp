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
        trialInstruction.checkOutTime = stoi(dataVector[i+2]);
        trialInstruction.returnTime = stoi(dataVector[i+3]);
        instructionsVector.push_back(trialInstruction);
    }
}

void stationVectorMaker(){
    for(int i = 0; i < instructionsVector.size(); i++){
        trialStationVector.name = instructionsVector[i].checkOutStation;
        trialStationVector.numberOfBikes = 15;
        vectorOfStationVectors.push_back(trialStationVector);
    }
}

void clockCounter(){
    int minutes = 0;
    while(minutes < 2880){
        //look at each struct in the instructionVector[i]
        //if minutes == instructionVector[i].checkOutTime, look at each vector in the stationsVector
        //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
        //else if minutes == instructionsVector[i].returnTime, look at each vector in the stationsVector
        //if instructionsVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
        //else do nothing
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
        dataVector.push_back(word);
        counter++;
    }
    
    inFile.close();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    file_to_array(dataArray, "divvyData.txt");
    cout << "Data Vector 0 = " << dataVector[0] << endl;
    cout << "Data Vector 1 = " << dataVector[1] << endl;
    cout << "Data Vector 2 = " << dataVector[2] << endl;
    cout << "Data Vector 3 = " << dataVector[3] << endl;
    cout << "Data Vector 4 = " << dataVector[4] << endl;
    cout << "Data Vector 5 = " << dataVector[5] << endl;
    cout << "Data Vector 6 = " << dataVector[6] << endl;
    cout << "Data Vector 7 = " << dataVector[7] << endl;
    cout << "Data Vector 8 = " << dataVector[8] << endl;
    cout << "Data Vector 9 = " << dataVector[9] << endl;
    cout << "Data Vector 10 = " << dataVector[10] << endl;
    cout << "Data Vector 11 = " << dataVector[11] << endl;
   
    instruction one;
    
    one.checkOutStation = dataVector[4];
    one.returnStation = dataVector[5];
    one.checkOutTime = stoi(dataVector[6]);
    one.returnTime = stoi(dataVector[7]);
    
    cout << "one.checkOutStation = " << one.checkOutStation << endl;
    cout << "one.returnStation = " << one.returnStation << endl;
    cout << "one.checkOutTime = " << one.checkOutTime << endl;
    cout << "one.returnTime = " << one.returnTime << endl;
    cout << "Counter = " << counter/4 << endl;

    instructionMaker();
    cout << "instructionVector[0].checkOutTime = " << instructionsVector[0].checkOutTime << endl;
    cout << "instructionVector[1].checkOutTime = " << instructionsVector[1].checkOutTime << endl;


    
    return 0;
}
