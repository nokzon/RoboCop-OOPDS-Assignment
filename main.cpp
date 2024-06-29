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
    
    // all of these code below are considered 1 step and to be enclosed in a for-loop as the simulation
    battlefield.printBattlefield();
    Robot* Kidd = battlefield.getRobot(0);
    Robot* Jet = battlefield.getRobot(1);
    Robot* Alpha = battlefield.getRobot(2);
    Robot* Beta = battlefield.getRobot(3);
    Robot* Star = battlefield.getRobot(4);

    Kidd->setGrid(battlefield);
    Jet->setGrid(battlefield);
    Alpha->setGrid(battlefield);
    Beta->setGrid(battlefield);
    Star->setGrid(battlefield);

    Kidd->setGameInfo(gameInfo);
    Jet->setGameInfo(gameInfo);
    Alpha->setGameInfo(gameInfo);
    Beta->setGameInfo(gameInfo);
    Star->setGameInfo(gameInfo);


    for (int i = 0; i < gameInfo.steps; ++i) {

        cout << endl << endl << "Steps: " << i + 1 << endl;
        battlefield.updateBattlefield();        
        battlefield.printBattlefield();
        for (int i = 0; i < gameInfo.robotCount; ++i)
        {
            Robot* robot = battlefield.getRobot(i);
            robot->look(0, 0);
            robot->move();
            robot->step();
            robot->fire();
            // This would work but some functions might not work
            // i.e. some robots use fire(x, y) instead of fire()
            // best approach is honestly to just fix fire to have one function lol
        }
        // Madbot
        Kidd->look(0, 0);
        Kidd->move();
        Kidd->step();
        Kidd->fire();

        // RoboTank
        Jet->look(0, 0);
        Jet->move();
        Jet->step();
        Jet->fire();

        // Terminator
        Alpha->look(0, 0);
        Alpha->move();
        Alpha->step();
        Alpha->fire(0, 0);

        // BlueThunder
        Beta->look(0, 0);
        Beta->move();
        Beta->step();
        Beta->fire();

        // RoboCop
        Star->look(0, 0);
        Star->move();
        Star->step();

        // this is the entire flow for a robocop's fire
        for (int i = 0; i < 3; i++) {
            int shootX = rand() % 21 - 10; // generate X between -10 to 10
            int shootY = rand() % 21 - 10;

            while (abs(shootX) + abs(shootY) > 10 || abs(shootX) + abs(shootY) == 0)
            {
                shootX = rand() % 21 - 10;
                shootY = rand() % 21 - 10;
            }
            Star->fire(shootX, shootY);
        }
    }

    return 0;
}
