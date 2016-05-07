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
//        cout << "instruction number " << counter << " just added to instructionsVector" << endl;
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

//void addFiveBikes(stationStruct structWithRoom){
//    structWithRoom.numberOfBikes = structWithRoom.numberOfBikes + 5;
//}
//
//void redistribute(stationStruct fullStruct){
//    fullStruct.numberOfBikes = fullStruct.numberOfBikes - 5;
//    for(int i = 0; i < vectorOfstationStructs.size(); i++){
//        if(vectorOfstationStructs[i].numberOfBikes > 20){
//            cout << "Redistribution Failed!" << endl;
//        }
//        else{
////            cout << "Redistribution Success!" << endl;
//            addFiveBikes(vectorOfstationStructs[i]);
//            cout << "Move 5 bikes to: " << vectorOfstationStructs[i].name << endl;
//            i = vectorOfstationStructs.size();
//        }
//    }
//}
//
//void checkOutEvents(int minutes){
//    //look at each struct in the instructionsVector[i]
//    for(int i = 0; i < instructionsVector.size(); i++){
//        //if minutes == instructionVector[i].checkOutTime, look at each struct in the vectorOfstationStructs
//        if(minutes == instructionsVector[i].checkOutTime){
//            cout << instructionsVector[i].checkOutStation << " just had a bike checked out at " << minutes << " minutes."<< endl;
//            for(int j = 0; j < vectorOfstationStructs.size(); j++){
//                //if instructionVector[i].checkOutStation == stationsVector[j], stationsVector[j] goes down 1
//                if(instructionsVector[i].checkOutStation.compare(vectorOfstationStructs[j].name) == 0){
////                    cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " << vectorOfstationStructs[j].name << endl;
//                    cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes - 1;
//                    cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                    if(vectorOfstationStructs[j].numberOfBikes < 0){
//                        cout << vectorOfstationStructs[j].name << " STATION IS NOW EMPTY: " << endl;
//                        //                        redistribute(vectorOfstationStructs[j]);
//                        //                            j = vectorOfstationStructs.size();
//                    }
//                    else{
//                        cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left." << endl;
//                        //                            j = vectorOfstationStructs.size();
//                    }
//                }
//                else{
////                    cout << "instructionsVector[i].checkOutStation is: " << instructionsVector[i].checkOutStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
//                    //                        j = vectorOfstationStructs.size();
//                }
//            }
//        }
//    }
//}
//
//void returnEvents(int minutes){
//    for(int i = 0; i < instructionsVector.size(); i++){
//        if(minutes == instructionsVector[i].returnTime){
//            cout << instructionsVector[i].returnStation << " just had a bike returned at " << minutes << " minutes."<< endl;
//            for(int j = 0; j < vectorOfstationStructs.size(); j++){
//                if(instructionsVector[i].returnStation == vectorOfstationStructs[j].name){
////                    cout << "A bike just got returned!" << endl;
////                    cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " << vectorOfstationStructs[j].name << endl;
//                    cout << vectorOfstationStructs[j].name << " just had " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                    vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes + 1;
//                    cout << vectorOfstationStructs[j].name << " now has " << vectorOfstationStructs[j].numberOfBikes << " bikes in it." << endl;
//                    if(vectorOfstationStructs[j].numberOfBikes > 30){
//                        cout << vectorOfstationStructs[j].name << " STATION IS NOW FULL: " << endl;
//                        vectorOfstationStructs[j].numberOfBikes = vectorOfstationStructs[j].numberOfBikes - 5;
//                        for(int k = 0; k < vectorOfstationStructs.size(); k++){
//                            if(vectorOfstationStructs[k].numberOfBikes > 20){
//                                cout << "Redistribution Failed!" << endl;
//                            }
//                            else{
//                                //            cout << "Redistribution Success!" << endl;
//                                cout << "Move 5 bikes to: " << vectorOfstationStructs[k].name << endl;
//                                stationStruct temp = vectorOfstationStructs[k];
//                                cout << "Target Station to get 5 bikes is: " << temp.name << " which currently has only " << temp.numberOfBikes << endl;
//                                temp.numberOfBikes = temp.numberOfBikes + 5;
//                                k = vectorOfstationStructs.size();
//                            }
//                        }
////                        redistribute(vectorOfstationStructs[j]);
////                        cout << "Redistribution just took place." << endl;
//                        //                            j = vectorOfstationStructs.size();
//                    }
//                    else{
//                        cout << vectorOfstationStructs[j].name << " has " << vectorOfstationStructs[j].numberOfBikes << " left." << endl;
//                        //                            j = vectorOfstationStructs.size();
//                    }
//                }
//                else{
////                    cout << "instructionsVector[i].returnStation is: " << instructionsVector[i].returnStation << " and vectorOfstationStructs[j].name is: " <<vectorOfstationStructs[j].name << endl;
//                    //                        j = vectorOfstationStructs.size();
//                }
//            }
//        }
//    }
//}

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
//        cout << word;
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
    
//    stationStructMakerCheckout();
    
    stationStructReturn();
    
//    for(int i = 0; i < vectorOfstationStructs.size(); i++){
//        cout << vectorOfstationStructs[i].name << " is in the vector!!!" << endl;
//        
//    }
    
//    stationVectorMaker();
//    stationChecker();
    
    clockCounter();

    cout << "\n\n\n" << endl;

    for(int i = 0; i < vectorOfstationStructs.size(); i++){
        cout << vectorOfstationStructs[i].name << " has " << vectorOfstationStructs[i].numberOfBikes << " bikes in it." << endl;
    }
//    cout << vectorOfstationStructs[0].name << endl;
//    << " has " << vectorOfstationStructs[0].numberOfBikes << "bikes in it."
    
    return 0;
}
