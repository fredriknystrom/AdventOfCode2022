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

bool containsDuplicate(vector<char> chars) {
	if (!is_sorted(chars.begin(), chars.end()))
		sort(chars.begin(), chars.end());

	return adjacent_find(chars.begin(), chars.end()) != chars.end();
}

int pointsFromFile(string fileName){

    ifstream myFileStream(fileName);
    string line, firstIDS, secondIDS;
    int position = 0;
  
    getline(myFileStream, line);

    vector<char> vector;

    for(int i = 0; i < line.length(); i++){
        vector.push_back(line[i]);
        ++position;
        if (vector.size() > 4){
            vector.erase(vector.begin());
        }
        if (vector.size() == 4 && !containsDuplicate(vector)){
            return position;
        }

    }
    myFileStream.close();
    return -1;
}

int main(){
    string fileName = "tuningTrouble.txt";
    cout << pointsFromFile(fileName);
    return 0;
}