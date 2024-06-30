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
        battlefield.getRobot(i)->setGrid(battlefield);
        battlefield.getRobot(i)->setGameInfo(gameInfo);
    }
    
    cout << "Initial battlefield: " << endl;
    battlefield.printBattlefield();
    // Robot* Kidd = battlefield.getRobot(0);
    // Robot* Jet = battlefield.getRobot(1);
    // Robot* Alpha = battlefield.getRobot(2);
    // Robot* Beta = battlefield.getRobot(3);
    // Robot* Star = battlefield.getRobot(4);

    // Kidd->setGrid(battlefield);
    // Jet->setGrid(battlefield);
    // Alpha->setGrid(battlefield);
    // Beta->setGrid(battlefield);
    // Star->setGrid(battlefield);

    // Kidd->setGameInfo(gameInfo);
    // Jet->setGameInfo(gameInfo);
    // Alpha->setGameInfo(gameInfo);
    // Beta->setGameInfo(gameInfo);
    // Star->setGameInfo(gameInfo);

    for (int i = 0; i < gameInfo.steps; ++i) {
        if (battlefield.checkOneRobotAlive()) {
            break;
        }
        cout << endl << endl << "Steps: " << i + 1 << endl;
        battlefield.updateBattlefield();        
        battlefield.printBattlefield();

        for (int i = 0; i < gameInfo.robotCount; ++i)
        {
            Robot* robot = battlefield.getRobot(i);          
            if (!(robot->isAlive())) { // check robot alive
                robot->reduceLives();
                if (robot->getLives() <= 0) { // kill robot when lives = 0
                    robot = nullptr;
                }
                else { // respawns robot
                    // int newPosY = rand() % gameInfo.M;
                    // int newPosX = rand() % gameInfo.N;
                    int newPosY = 12; // to test for one robot alive and upgrading robot
                    int newPosX = 1; // to test for one robot alive and upgrading robot
                    if (!(battlefield.findRobotAtPosition(newPosY, newPosX))) {
                        robot->setPosY(newPosY);
                        robot->setPosX(newPosX);
                        robot->toggleAliveState();
                        cout << robot->getName() << " respawned at (" << newPosY << ", " << newPosX << ")" << endl;
                    }
                    else { // start test case to test for one robot alive and upgrading robot
                        newPosY = 13;
                        newPosX = 1;
                        robot->setPosY(newPosY);
                        robot->setPosX(newPosX);
                        robot->toggleAliveState();
                        cout << robot->getName() << " respawned at (" << newPosY << ", " << newPosX << ")" << endl;
                    } // end test case to test for one robot alive and upgrading robot
                }
            }
            if (robot) {           
                // if (robot->getKills() >= 3) { // start test case to test for upgrading robot
                //     gameInfo.upgradeRobot(robot, "TerminatorRoboCop");
                //     robot->setKills(0);
                // } end test case to test for upgrading robot
                robot->look(0, 0);
                robot->move();
                robot->step();
                robot->fire();
                for (int i = 0; i < 3; i++) {
                    int shootX = rand() % 21 - 10; // generate X between -10 to 10
                    int shootY = rand() % 21 - 10;

                    while (abs(shootX) + abs(shootY) > 10 || abs(shootX) + abs(shootY) == 0)
                    {
                        shootX = rand() % 21 - 10;
                        shootY = rand() % 21 - 10;
                    }
                    robot->fire(shootY, shootX);
                }
            }
        }
    }

    cout << "\nGame Over!" << endl;

    return 0;
}