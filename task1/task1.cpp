#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;


int readFile(string inputFile){
    ifstream MyReadFile(inputFile);
    string myText;
    std::list<int> listOfSums;
    int sumOfInts = 0;

    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        if (myText.length() != 0){
            sumOfInts += stoi(myText); 
        }
        else {
            listOfSums.push_back(sumOfInts);
            sumOfInts = 0;
        }
    }
    MyReadFile.close();
    listOfSums.sort();
    int first, second, third;
    first = *max_element(listOfSums.begin(), std::prev(listOfSums.end(), 0));
    second = *max_element(listOfSums.begin(), std::prev(listOfSums.end(), 1));
    third = *max_element(listOfSums.begin(), std::prev(listOfSums.end(), 2));
    return first + second + third;
}


int main(){
    string fileName = "calories.txt";
    cout << readFile(fileName);
    return 0;
}



    


