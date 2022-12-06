#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// decoding symbols to R, P, S
string decodeRockPapperScissor(string s, string symbols[3]){
    if(s == symbols[0]){
        s = "R";
    }
    else if (s == symbols[1]){
        s = "P";
    }
    else if (s == symbols[2]){
        s = "S";
    }
    return s;
}

// returns right symbol depending on result and opponent symbol
string getFixedResultSymbol(string opponent, string result){
    if(result == "X"){
        if (opponent == "R"){
            return "S";
        }
        if (opponent == "P"){
            return "R";
        }
        if (opponent == "S"){
            return "P";
        }
    }
    if(result == "Y"){
        return opponent;
    }
    if(result == "Z"){
        if (opponent == "R"){
            return "P";
        }
        if (opponent == "P"){
            return "S";
        }
        if (opponent == "S"){
            return "R";
        }
    }
    return "";
}

// returns X = lose = 0, Y = tie = 3, Z = win = 6
int outcomeOfMatch(string s){
    if (s == "X"){
        return 0;
    }
    else if (s == "Y"){
        return 3;
    }
    else if (s == "Z"){
        return 6;
    }
    return 0;
}

// returns 1 if R, 2 if P, 3 if S
int pointsOfSymbol(string s){
    if (s == "R"){
        return 1;
    }
    else if (s == "P"){
        return 2;
    }
    else if (s == "S"){
        return 3;
    }
    return 0;
}

int evalPoints(string fileName){

    std::ifstream infile(fileName);
    string opponent, me, result;
    int points = 0;
    string opponentSymbols[3] = {"A", "B", "C"};
    string mySymbols[3] = {"X", "Y", "Z"};

    while (infile >> opponent >> result)
    {
        opponent = decodeRockPapperScissor(opponent, opponentSymbols);
        me = getFixedResultSymbol(opponent, result);
        points += pointsOfSymbol(me);
        points += outcomeOfMatch(result);
    }
    return points;
}


int main(){
    string fileName = "rockPapperScissor.txt";
    cout << evalPoints(fileName);
    return 0;
}