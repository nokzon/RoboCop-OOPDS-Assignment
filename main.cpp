#include <iostream>
#include <ctime>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    string filename = "input.txt";

    GameInfo gameInfo;
    gameInfo.readFile(filename);
    gameInfo.printGameInfo();    // Print the parsed information to verify it

    Battlefield battlefield(gameInfo);
    battlefield.printBattlefield(gameInfo);

    // gameInfo.deleteRobots();
    
    // Moved to function deleteRobots()
    // for (int i = 0; i < gameInfo.robotCount; ++i){
    //     delete gameInfo.robots[i];
    // }
    // delete[] gameInfo.robots;

    return 0;
}
