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

int contains(int firstLow, int firstHigh, int secondLow, int secondHigh){

    if (secondLow >= firstLow && secondHigh <= firstHigh){
        return 1;
    }
    else if (firstLow >= secondLow && firstHigh <= secondHigh){
        return 1;
    }
    return 0;
}

int containsCheck(string firstIDS, string secondIDS){
    string firstLowID, firstHighID, secondLowID, secondHighID;
    stringstream s1(firstIDS);
    getline(s1, firstLowID, '-');
    getline(s1, firstHighID, '-');
    stringstream s2(secondIDS);
    getline(s2, secondLowID, '-');
    getline(s2, secondHighID, '-');

    return contains(stoi(firstLowID), stoi(firstHighID), stoi(secondLowID), stoi(secondHighID));
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
       
        points += containsCheck(firstIDS, secondIDS);
    }
   
    myFileStream.close();
    return points;
}

int main(){
    string fileName = "pairID.txt";
    cout << pointsFromFile(fileName);
    return 0;
}