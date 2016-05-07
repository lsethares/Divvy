//
//  main.cpp
//  DivvyProject
//
//  Created by Jason Burkett on 4/22/16.
//  Copyright © 2016 Jason Burkett. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

//create an ifstream object to read data in from files
ifstream inFile;
//create a string called word to store each element being read in from file
string word;
//create a vector called dataVector to contain all elements from the .txt file
vector<string> dataVector;

//create a counter of type int to keep track of things
int counter = 0;

//create a struct called instruction that will hold the different instruction information read in from the file
struct instruction{
    string checkOutStation;
    string returnStation;
    int checkOutTime;
    int returnTime;
};

//create a vector of instruction structs called instructionsVector to hold all of the instructions structs
vector<instruction> instructionsVector;

//create an instruction called trialInstruction which will hold all the data from the file
instruction trialInstruction;

//create a struct called stationStruct that will hold different information about the stations
struct stationStruct{
    string name;
    int numberOfBikes;
};

//create a vector of stationStructs that will hold all of the stationStructs
vector<stationStruct> vectorOfstationStructs;

//create a stationStruct called stationStruct which will hold station information and help that info be stored in a vector
stationStruct trialstationStruct;

//create a function that creates an instruction from the information in dataVector
void instructionMaker(){
    int i = 0;
    while(i < 1880){
        i = i + 4;
        trialInstruction.checkOutStation = dataVector[i];
        trialInstruction.returnStation = dataVector[i+1];
        //convert the time from the file into minutes
        trialInstruction.checkOutTime = ((stoi(dataVector[i+2]))/100)*60+(stoi(dataVector[i+2])%100);
        trialInstruction.returnTime = ((stoi(dataVector[i+3]))/100)*60+(stoi(dataVector[i+3])%100);
        //add this instruction into the instructionsVector
        instructionsVector.push_back(trialInstruction);
        counter++;
    }
}

//create a function that will look at each instruction from the instructionsVector and create a stationStruct with that information
void stationStructMakerCheckout(){
//    cout << instructionsVector.size() << endl;
    for(int i = 0; i < instructionsVector.size(); i++){
        trialstationStruct.name = instructionsVector[i].checkOutStation;
        trialstationStruct.numberOfBikes = 10;
        //add the modified struct to the vectorOfstationStructs
            bool is_in = false;
                for(int j = 0; j < vectorOfstationStructs.size(); j++){
                    if(vectorOfstationStructs[j].name == trialstationStruct.name){
                        is_in = true;
                        j = vectorOfstationStructs.size();
                    }
                }
            if(!is_in){
                        vectorOfstationStructs.push_back(trialstationStruct);
//                        cout << trialstationStruct.name << " stationStruct just added to vectorOfstationStructs based on checkOutStationName" << endl;
                    }
                    else{
//                        cout << trialstationStruct.name << "already exists!" << endl;
                    }
        }
}

//create a function that will look at each instruction from the instructionsVector and create a stationStruct with that information
void stationStructReturn(){
    //    cout << instructionsVector.size() << endl;
    for(int i = 0; i < instructionsVector.size(); i++){
        trialstationStruct.name = instructionsVector[i].returnStation;
        trialstationStruct.numberOfBikes = 15;
        //add the modified struct to the vectorOfstationStructs
        bool is_in = false;
        for(int j = 0; j < vectorOfstationStructs.size(); j++){
            if(vectorOfstationStructs[j].name == trialstationStruct.name){
                is_in = true;
                j = vectorOfstationStructs.size();
            }
        }
        if(!is_in){
            vectorOfstationStructs.push_back(trialstationStruct);
//            cout << trialstationStruct.name << " stationStruct just added to vectorOfstationStructs based on checkOutStationName" << endl;
        }
        else{
//            cout << trialstationStruct.name << "already exists!" << endl;
        }
    }
}

//create a function to check out bikes and redistribute if necessary
void checkOutEvents(int minutes){
    //look at each struct in the instructionsVector[i]
    for(int i = 0; i < instructionsVector.size(); i++){
        //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
        if(minutes == instructionsVector[i].checkOutTime){
            cout << instructionsVector[i].checkOutStation << " should have a bike checked out at " << minutes << " minutes." << endl;
            for(int j = 0; j < vectorOfstationStructs.size(); j++){
                //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
                if(instructionsVector[i].checkOutStation.compare(vectorOfstationStructs[j].name) == 0){
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfStations[j].name << endl;
                    //cout << vectorOfStations[j].name << " just had " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes - 1;
                    //cout << vectorOfStations[j].name << " now has " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    if (vectorOfstationStructs[j].numberOfBikes <= 10)
                    {
                        //move ten bikes to vectorOfStiaions[j]
                        vectorOfstationStructs[j].numberOfBikes += 10;
                        cout << "This station is running low, so ten bikes have been moved to " << vectorOfstationStructs[j].name << endl;
                        //remove ten bikes from a random station
                        int random = rand()%10 + 9;
                        while(vectorOfstationStructs[random].numberOfBikes < 10)random = rand()%10+9;
                        vectorOfstationStructs[random].numberOfBikes -= 10;
                    }
                    //                    if(vectorOfStations[j].numberOfBikes < 0){
                    //                        cout << vectorOfStations[j].name << " STATION IS NOW EMPTY: \n" << endl;
                    //                        //                        redistribute(vectorOfstationStructs[j]);
                    //                        //                            j = vectorOfstationStructs.size();
                    cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left.\n" << endl;
                    //                            j = vectorOfstationStructs.size();
                    
                }
                else{
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " <<vectorOfStations[j].name << endl;
                    //                        j = vectorOfstationStructs.size();
                }
            }
        }
    }
}

//create a function to return bikes and redistribute if necessary
void returnEvents(int minutes){
    for(int i = 0; i < instructionsVector.size(); i++){
        if(minutes == instructionsVector[i].returnTime){
            cout << instructionsVector[i].returnStation << " should have a bike returned at " << minutes << " minutes." << endl;
            for(int j = 0; j < vectorOfstationStructs.size(); j++){
                //if instructionVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
                if(instructionsVector[i].returnStation.compare(vectorOfstationStructs[j].name) == 0){
                    //cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfStations[j].name << endl;
                    //cout << vectorOfStations[j].name << " just had " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes + 1;
                    //cout << vectorOfStations[j].name << " now has " << vectorOfStations[j].numberOfBikes << " bikes in it." << endl;
                    
                    //redistribution
                    if (vectorOfstationStructs[j].numberOfBikes > 30)
                    {
                        //move ten bikes to vectorOfStiaions[j]
                        vectorOfstationStructs[j].numberOfBikes -= 10;
                        cout << "This station is full, so ten bikes have been moved from " << vectorOfstationStructs[j].name << endl;
                        //add ten bikes to a random station
                        int random = rand()%10 + 9;
                        while(vectorOfstationStructs[random].numberOfBikes > 20)random = rand()%10+9;
                        vectorOfstationStructs[random].numberOfBikes += 10;
                    }
                    
                    //                    if(vectorOfStations[j].numberOfBikes < 0){
                    //                        cout << vectorOfStations[j].name << " STATION IS NOW EMPTY: \n" << endl;
                    //                        redistribute(vectorOfstationStructs[j]);
                    //                            j = vectorOfstationStructs.size();
                    //                    }
                    //                    else{
                    cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left.\n" << endl;
                    //                            j = vectorOfstationStructs.size();
                    //                    }
                }
                else{
                    //cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfStations[j].name << endl;
                    //                        j = vectorOfstationStructs.size();
                }
            }
        }
    }
}

//create a function that cycles through all possible minutes (until the last instruction) and checks out and returns bikes
void clockCounter(){
    int minutes = 0;
    while(minutes < 1435){
        checkOutEvents(minutes);
        returnEvents(minutes);
        minutes++;
    }
}


//create a function called file_to_array that takes in a file name and an empty vector and populates it with the data from the file provided
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
//        cout << word;
        dataVector.push_back(word);
//        counter++;
//        cout << counter << endl;
    }
    cout << " \n" << endl;
    inFile.close();
}

//execute the main function of the program which calls all the other functions to make the program run
int main(int argc, const char * argv[]) {

    file_to_array(dataVector, "divvyData.txt");
    
    instructionMaker();
    
//    stationStructMakerCheckout();
    
    stationStructReturn();
    
    clockCounter();

    cout << "\n\n\n" << endl;

    //print out values of each station at the end
    for(int i = 0; i < vectorOfstationStructs.size(); i++){
        cout << vectorOfstationStructs[i].name << " has " << vectorOfstationStructs[i].numberOfBikes << " bikes in it." << endl;
    }
    
    return 0;
}
