#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

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

// returns 6 if a win, 3 for tie, 0 for b win
int getWinner(string player1, string player2){
    if (player1 == "R"){
        if (player2 == "P"){
            return 0;
        }
        else if (player2 == "S"){
            return 6;
        }
    }
    if (player1 == "P"){
        if (player2 == "S"){
            return 0;
        }
        else if (player2 == "R"){
            return 6;
        }
    }
    if (player1 == "S"){
        if (player2 == "R"){
            return 0;
        }
        else if (player2 == "P"){
            return 6;
        }
    }
    return 3;
}

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
    string opponent, me;
    int points = 0;
    string opponentSymbols[3] = {"A", "B", "C"};
    string mySymbols[3] = {"X", "Y", "Z"};

    while (infile >> opponent >> me)
    {
        opponent = decodeRockPapperScissor(opponent, opponentSymbols);
        me = decodeRockPapperScissor(me, mySymbols);
        points += pointsOfSymbol(me);
        points += getWinner(me, opponent);
    }
    return points;
}


int main(){
    string fileName = "rockPapperScissor.txt";
    cout << evalPoints(fileName);
    return 0;
}


