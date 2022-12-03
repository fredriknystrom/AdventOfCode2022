#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;


char getItemInBoth(string s){
    int mid = s.length()/2;
    for(int i = 0; i < mid; i++){
        char c = s[i];
        for(int j = mid; j < s.length(); j++){
            if (c == s[j]){
                return c;
            }
        }
    }
    return 'a';
}

// point system: a-z (1-26), A-Z (27-52)
int pointsFromChar(char c){
    int asciiValue = int(c);
    if (isupper(asciiValue) != 0){
        return (asciiValue - 38);
    }

    return (asciiValue - 96);
}


int pointsFromFile(string fileName){
   
    ifstream MyReadFile(fileName);
    string myLine;
    char c;
    int points = 0;

    while (getline (MyReadFile, myLine)) {
        c = getItemInBoth(myLine);
        points += pointsFromChar(c);
    }
    MyReadFile.close();
    return points;
}


int main(){
    string fileName = "rucksack.txt";
    cout << pointsFromFile(fileName);
    return 0;
}