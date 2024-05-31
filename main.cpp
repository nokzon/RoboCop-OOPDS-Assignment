#include <iostream>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    string filename = "input.txt";
    gameInfo gameInfo = readFile(filename);
    printGameInfo(gameInfo);    // Print the parsed information to verify it
    
    for (int i = 0; i < gameInfo.robotCount; ++i){
        delete gameInfo.robots[i];
    }
    delete[] gameInfo.robots;

    return 0;
}
