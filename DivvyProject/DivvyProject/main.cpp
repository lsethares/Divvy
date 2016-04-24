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

//create a function called file_to_array that takes in a file name and an empty array and populates it with the data from the file provided
void file_to_array(string arrayProvided[], string fileName){
    inFile.open(fileName);
    //if the file has a problem opening, output an error message
    if(!inFile.is_open())
    {
        cout << "Problem Opening File" << endl;
    }
    //if there's no problem, add all data to an array, printing them to console as they're added to look for mistakes
//    int index = 0;
    while(!inFile.eof()){
        getline(inFile, word, ',');
        cout << word;
        dataVector.push_back(word);
        
//        arrayProvided[index] = word;
//        index++;
    }
    
    inFile.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    file_to_array(dataArray, "divvyData.txt");
    cout << dataVector[0] << endl;
    cout << dataVector[1] << endl;
    cout << dataVector[2] << endl;
    cout << dataVector[3] << endl;
    cout << dataVector[4] << endl;
    cout << dataVector[5] << endl;
    cout << dataVector[6] << endl;
    cout << dataVector[7] << endl;
    cout << dataVector[8] << endl;
    cout << dataVector[9] << endl;
    cout << dataVector[10] << endl;
    cout << dataVector[11] << endl;
    

    return 0;
}
