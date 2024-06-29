#include <iostream>
#include <ctime>
#include "battlefield.hpp"
#include "battlefield.cpp"
#include "gameinfo.hpp"
#include "gameinfo.cpp"
#include "robots.cpp"
using namespace std;

int main()
{

    srand(time(NULL));
    string fileName = "input.txt";
    int aliveBotCounter = 0;


    GameInfo gameInfo;
    gameInfo.readFile(fileName);
    gameInfo.printGameInfo(); // Print the parsed information to verify it
    gameInfo.printRobotStatus();

    Battlefield battlefield(gameInfo);


    // Add robots to the battlefield
    for (int i = 0; i < gameInfo.robotCount; ++i)
    {
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

    for (int i = 0; i < gameInfo.steps; ++i)
    {
        cout << endl
             << endl
             << "Steps: " << i + 1 << endl;
        battlefield.updateBattlefield();
        battlefield.printBattlefield();
        for (int i = 0; i < gameInfo.robotCount; ++i)
        {
            Robot *robot = battlefield.getRobot(i);
            if (!(robot->isAlive()))
            {
                robot->reduceLives();
                if (robot->getLives() == 0)
                {
                    robot = nullptr;
                }
                else
                {
                    robot->toggleAliveState();
                    // respawn robot;
                }
            }
            if (robot)
            {
                robot->look(0, 0);
                robot->move();
                robot->step();
                robot->fire();
                for (int i = 0; i < 3; i++)
                {
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
    //Simulation Ended

   
    cout<<"-------------------------------------------------------"<<endl;
    cout << " ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout << " ███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀" << endl;
    cout << " ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼" << endl;
    cout << " ██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀" << endl;
    cout << " ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼" << endl;
    cout << " ███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄" << endl;
    cout << " ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout << " ███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼" << endl;
    cout << " ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
    cout << " ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼" << endl;
    cout << " ██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
    cout << " ███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄" << endl;
    cout << " ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout<<"-------------------------------------------------------"<<endl;
    
   

    for (int i = 0; i < 5; ++i){

        Robot *robot = battlefield.getRobot(i);
        //Check if Bot is Alive or Dead ☠️

        if (robot->isAlive()){
            cout << "Bot ";
            cout << robot->getName();
            cout << " is Alive" << endl;
            aliveBotCounter++;
        }

        else{
            cout << "Bot ";
            cout << robot->getName();
            cout << " is Dead " << endl;
        }
    }

    cout << "------------------------Summary------------------------" << endl;

    if (aliveBotCounter > 1){
        cout << "Game is Draw" << endl;
    }

    else if (aliveBotCounter == 1){
        for (int i = 0; i < 5; ++i){

            Robot *robot = battlefield.getRobot(i);
            if (robot->isAlive()){
                cout << "Bot ";
                cout << robot->getName();
                cout << "WON! ";
            }
        }
    }
}
