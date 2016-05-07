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
//create a vector called ClarkAndRandolf to store Bikes in
//vector<int> ClarkAndRandolf;

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
        cout << "instruction number " << counter << " just added to instructionsVector" << endl;
    }
}

//create a function that will look at each instruction from the instructionsVector and create a stationStruct with that information
void stationStructMakerCheckout(){
//    cout << instructionsVector.size() << endl;
    for(int i = 0; i < instructionsVector.size(); i++){
        trialstationStruct.name = instructionsVector[i].checkOutStation;
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
                        cout << trialstationStruct.name << " stationStruct just added to vectorOfstationStructs based on checkOutStationName" << endl;
                    }
                    else{
                        cout << trialstationStruct.name << "already exists!" << endl;
                    }
        }
}

void redistribute(stationStruct fullVector){
    for(int i = 0; i < vectorOfstationStructs.size(); i++){
        if(vectorOfstationStructs[i].numberOfBikes <= 10){
            fullVector.numberOfBikes -= 10;
            vectorOfstationStructs[i].numberOfBikes += 10;
            cout << "10 bikes were just received at " << vectorOfstationStructs[i].name << endl;
        }
        else{}
    }
}

void checkOutEvents(int minutes){
    //look at each struct in the instructionsVector[i]
    for(int i = 0; i < instructionsVector.size(); i++){
        //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
        if(minutes == instructionsVector[i].checkOutTime){
            cout << instructionsVector[i].checkOutStation << " should have a bike checked out at " << minutes << " minutes."<< endl;
            for(int j = 0; j < vectorOfstationStructs.size(); j++){
                //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
                if(instructionsVector[i].checkOutStation.compare(vectorOfstationStructs[j].name) == 0){
                    cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfstationStructs[j].name << endl;
                    cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes - 1;
                    cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
                    if(vectorOfstationStructs[j].numberOfBikes < 0){
                        cout << vectorOfstationStructs[j].name << " STATION IS NOW EMPTY: " << endl;
                        //                        redistribute(vectorOfstationStructs[j]);
                        //                            j = vectorOfstationStructs.size();
                    }
                    else{
                        cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left." << endl;
                        //                            j = vectorOfstationStructs.size();
                    }
                }
                else{
                    cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
                    //                        j = vectorOfstationStructs.size();
                }
            }
        }
    }
}

void returnEvents(int minutes){
    for(int i = 0; i < instructionsVector.size(); i++){
        if(minutes == instructionsVector[i].returnTime){
            cout << instructionsVector[i].returnStation << " should have a bike returned at " << minutes << " minutes."<< endl;
            for(int j = 0; j < vectorOfstationStructs.size(); j++){
                if(instructionsVector[i].returnStation.compare(vectorOfstationStructs[j].name) == 0){
                    cout << "A bike just got returned!" << endl;
                    cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " << vectorOfstationStructs[j].name << endl;
                    cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes + 1;
                    cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
                    if(vectorOfstationStructs[j].numberOfBikes > 30){
                        cout << vectorOfstationStructs[j].name << " STATION IS NOW FULL: " << endl;
                        //                        redistribute(vectorOfstationStructs[j]);
                        //                            j = vectorOfstationStructs.size();
                    }
                    else{
                        cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left." << endl;
                        //                            j = vectorOfstationStructs.size();
                    }
                }
                else{
                    cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
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


//void clockCounter(){
//    int minutes = 0;
//    while(minutes < 1435){
//        //look at each struct in the instructionsVector[i]
//        for(int i = 0; i < instructionsVector.size(); i++){
//            //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
//            if(minutes == instructionsVector[i].checkOutTime){
//                cout << instructionsVector[i].checkOutStation << " should have a bike checked out at " << minutes << " minutes."<< endl;
//                for(int j = 0; j < vectorOfstationStructs.size(); j++){
//                    //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
//                    if(instructionsVector[i].checkOutStation.compare(vectorOfstationStructs[j].name) == 0){
//                        cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfstationStructs[j].name << endl;
//                        cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                        vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes - 1;
//                        cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                        if(vectorOfstationStructs[j].numberOfBikes < 0){
//                            cout << vectorOfstationStructs[j].name << " STATION IS NOW EMPTY: " << endl;
//                            //                        redistribute(vectorOfstationStructs[j]);
////                            j = vectorOfstationStructs.size();
//                        }
//                        else{
//                            cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left." << endl;
////                            j = vectorOfstationStructs.size();
//                        }
//                    }
//                    else{
//                         cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
////                        j = vectorOfstationStructs.size();
//                    }
//                }
//            }
//            //else if minutes == instructionsVector[i].returnTime, look at each vector in the stationsVector
//            else if(minutes == instructionsVector[i].returnTime){
//                cout << instructionsVector[i].returnStation << " should have a bike returned at " << minutes << " minutes."<< endl;
//                for(int j = 0; j < vectorOfstationStructs.size(); j++){
//                    //if instructionsVector[i].returnStation == stationsVector[j], stationsVector[j] goes up 1
//                    if(instructionsVector[i].returnStation.compare(vectorOfstationStructs[j].name) == 0){
////                        cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
//                        cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                        vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes + 1;
//                        cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
////                        j = vectorOfstationStructs.size();
//                        if(vectorOfstationStructs[j].numberOfBikes >= 30){
//                            cout << vectorOfstationStructs[j].name << " STATION IS NOW FULL: " << endl;
////                            cout << "10 bikes were just removed from " << vectorOfstationStructs[j].name << endl;
//                            //call the redistribute function which checks if any vector in the stationsVector is full, if one is it takes away 10 bikes and prints a message saying so, then it checks for a vector in the stationsVector that has less than 10 bikes and adds 10 bikes and prints a message saying so
////                            redistribute(vectorOfstationStructs[j]);
////                            j = vectorOfstationStructs.size();
//                        }
//                        else{
//                            cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << "in it." << endl;
//                        }
//                    }
//                else{
//                    cout << "instructionsVector[i].return is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
//                }
//            }
//        }
//        //else do nothing
//        else{
////            cout << "Nothing going on during minute: " << minutes << " at " << instructionsVector[i].checkOutStation << " or " << instructionsVector[i].returnStation << endl;
//        }
//        }
//
//        minutes++;
//    }
//}

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
    
    stationStructMakerCheckout();
    
//    stationStructMakerReturn();
    
    for(int i = 0; i < vectorOfstationStructs.size(); i++){
        cout << vectorOfstationStructs[i].name << " is in the vector!!!" << endl;
    }
    
//    stationVectorMaker();
//    stationChecker();
    
    clockCounter();
//    cout << vectorOfstationStructs[0].name << endl;
//    << " has " << vectorOfstationStructs[0].numberOfBikes << "bikes in it."
    
    return 0;
}
