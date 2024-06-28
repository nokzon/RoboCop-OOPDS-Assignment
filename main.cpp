#include <iostream>
#include <ctime>
#include "battlefield.hpp"
#include "battlefield.cpp"
#include "gameinfo.hpp"
#include "gameinfo.cpp"
#include "robots.hpp"
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
    // for (int i = 0; i < gameInfo.robotCount; ++i) {
    //     battlefield.addRobot(gameInfo.robots[i]);
    // }
    
    // battlefield.printBattlefield();
    // cout << "Step 1: " << endl;
    // int randNumX = rand() % 21 - 10;
    // int randNumY = rand() % 21 - 10;
    // if (!(abs(randNumX) + abs(randNumY) > 10 || abs(randNumX) + abs(randNumY) == 0))
    // {
    //     if (!(robot.posX + randNumX > gameInfo.N || robot.posX + randNumX > gameInfo.M))
    // }
    // battlefield.getRobot(0)->fire(randNumX, randNumY);
    // battlefield.getRobot(0)->printInfo();

    return 0;
}
