#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int overlap(int firstLow, int firstHigh, int secondLow, int secondHigh){
    if (firstLow > secondHigh || firstHigh < secondLow){
        return 0;
    }
    return 1;
}

int overlapCheck(string firstIDS, string secondIDS){
    string firstLowID, firstHighID, secondLowID, secondHighID;
    stringstream s1(firstIDS);
    getline(s1, firstLowID, '-');
    getline(s1, firstHighID, '-');
    stringstream s2(secondIDS);
    getline(s2, secondLowID, '-');
    getline(s2, secondHighID, '-');

    return overlap(stoi(firstLowID), stoi(firstHighID), stoi(secondLowID), stoi(secondHighID));
}

int pointsFromFile(string fileName){

    ifstream myFileStream(fileName);
    string line, firstIDS, secondIDS;
    int points = 0;
  
    while(getline(myFileStream, line)){

        vector<string> vector;

        stringstream ss(line);
        getline(ss, firstIDS, ',');
        getline(ss, secondIDS, ',');
       
        points += overlapCheck(firstIDS, secondIDS);
    }
   
    myFileStream.close();
    return points;
}

int main(){
    string fileName = "pairID.txt";
    cout << pointsFromFile(fileName);
    return 0;
}