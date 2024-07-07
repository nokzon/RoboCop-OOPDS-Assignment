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
    ofstream outFile("output.txt");

    GameInfo gameInfo;
    gameInfo.readFile(fileName);
    gameInfo.printGameInfo();    // Print the parsed information to verify it
    gameInfo.printRobotStatus();

    Battlefield battlefield(gameInfo);

    // Add robots to the battlefield
    for (int i = 0; i < gameInfo.robotCount; ++i) {
        battlefield.addRobot(gameInfo.robots[i]);
        battlefield.getRobot(i)->setGrid(battlefield);
        battlefield.getRobot(i)->setGameInfo(gameInfo);
    }
    
    cout << "Initial battlefield: " << endl;
    outFile << "Initial battlefield: " << endl;
    battlefield.printBattlefield();
    battlefield.outputBattlefield(outFile);

    for (int i = 0; i < gameInfo.steps; ++i) {
        if (battlefield.checkOneRobotAlive()) { // if one robot is alive
            break;
        }
        cout << endl << endl << "Steps: " << i + 1 << endl;
        outFile << endl << endl << "Steps: " << i + 1 << endl;
        battlefield.updateBattlefield();        
        battlefield.printBattlefield();
        battlefield.outputBattlefield(outFile);

        for (int i = 0; i < gameInfo.robotCount; ++i)
        {
            Robot* robot = battlefield.getRobot(i);          
            if (!(robot->isAlive())) { // check robot alive
                robot->reduceLives();
                if (robot->getLives() <= 0) { // kill robot when lives = 0
                    robot = nullptr;
                }
                else { // respawns robot
                    int newPosY = rand() % gameInfo.M;
                    int newPosX = rand() % gameInfo.N;
                    if (!(battlefield.findRobotAtPosition(newPosY, newPosX))) {
                        robot->setPosY(newPosY);
                        robot->setPosX(newPosX);
                        robot->toggleAliveState();
                        cout << robot->getName() << " respawned at (" << newPosY << ", " << newPosX << ")" << endl;
                        outFile << robot->getName() << " respawned at (" << newPosY << ", " << newPosX << ")" << endl;
                    }
                }
            }
            if (robot) {           
                // if (robot->getKills() >= 3) { // start test case to test for upgrading robot
                    // if (robot->getType() == "RoboCop" || robot->getType() == "Terminator"){
                    //     battlefield.upgradeRobot(robot, "TerminatorRoboCop", outFile);
                    // }
                    // if (robot->getType() == "TerminatorRoboCop"){
                    //     battlefield.upgradeRobot(robot, "UltimateRobot", outFile);
                    // }
                    // if (robot->getType() == "BlueThunder"){
                    //     battlefield.upgradeRobot(robot, "MadBot", outFile);
                    // }
                    // if (robot->getType() == "MadBot"){
                    //     battlefield.upgradeRobot(robot, "RoboTank", outFile);
                    // }
                    // if (robot->getType() == "RoboTank"){
                    //     battlefield.upgradeRobot(robot, "UltimateRobot", outFile);
                    // }
                    // robot->setKills(0);
                // end test case to test for upgrading robot
                // else {
                    robot->look(outFile, 0, 0);
                    robot->move(outFile);
                    robot->step(outFile);
                    robot->fire(outFile);
                    for (int i = 0; i < 3; i++) {
                        int shootX = rand() % 21 - 10; // generate X between -10 to 10
                        int shootY = rand() % 21 - 10;

                        while (abs(shootX) + abs(shootY) > 10 || abs(shootX) + abs(shootY) == 0)
                        {
                            shootX = rand() % 21 - 10;
                            shootY = rand() % 21 - 10;
                        }
                        robot->fire(outFile, shootY, shootX);
                    }
                }
            }
        }
    

    cout << "\nGame Over!" << endl;
    outFile << "\nGame Over!" << endl;

    outFile.close();

    return 0;
}