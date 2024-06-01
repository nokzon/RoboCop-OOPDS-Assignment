#include <iostream>
#include <ctime>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    srand(time(0)); // Initialize random seed

    string filename = "input.txt";
    GameInfo gameInfo;

    gameInfo.readFile(filename);
    gameInfo.printGameInfo();    // Print the parsed information to verify it
    
    for (int step = 0; step < gameInfo.steps; ++step) {
        cout << "Step " << step + 1 << ":" << endl;
        gameInfo.printGrid();
    }
    
    // gameInfo.deleteRobots();
    
    // Moved to function deleteRobots()
    // for (int i = 0; i < gameInfo.robotCount; ++i){
    //     delete gameInfo.robots[i];
    // }
    // delete[] gameInfo.robots;

    return 0;
}
