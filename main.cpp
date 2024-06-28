#include <iostream>
#include <ctime>
#include "battlefield.hpp"
#include "battlefield.cpp"
#include "gameinfo.hpp"
#include "gameinfo.cpp"
#include "robots.cpp"
using namespace std;


int main() {
    srand(time(NULL));
    string fileName = "input.txt";

    GameInfo gameInfo;
    gameInfo.readFile(fileName);
    gameInfo.printGameInfo();    // Print the parsed information to verify it
    gameInfo.printRobotStatus();

    Battlefield battlefield(gameInfo);

    // Add robots to the battlefield
    for (int i = 0; i < gameInfo.robotCount; ++i) {
        battlefield.addRobot(gameInfo.robots[i]);
    }
    
    battlefield.printBattlefield();

    return 0;
}
