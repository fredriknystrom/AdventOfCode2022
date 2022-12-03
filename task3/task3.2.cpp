#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;


int getFileSize(string fileName){
 
string line;   // To read each line from code
int count = 0;    // Variable to keep count of each line
ifstream myFile(fileName);  
if(myFile.is_open()){
    while(myFile.peek()!=EOF)
    {
    getline(myFile, line);
    count++;
    }
    myFile.close();
    return count;
}
else{
    cout << "Couldn't open the file\n";
}
return 0;
}

int charInString(char c, string s){
    for(int i = 0; i < s.length(); i++){
            if (c == s[i]){
                return 1;
            }
        }
    return 0;
}

char itemInAllThree(string s1, string s2, string s3){
    for(int i = 0; i < s1.length(); i++){
        char c = s1[i];
        if (charInString(c, s2) && charInString(c, s3)){
            return c;
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
    int fileSize = getFileSize(fileName);
    ifstream MyReadFile(fileName);
    string line1, line2, line3;
    char c;
    int points = 0;

    for(int i; i < fileSize; i += 3){
        getline(MyReadFile, line1);
        getline(MyReadFile, line2);
        getline(MyReadFile, line3);
        c = itemInAllThree(line1, line2, line3);
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