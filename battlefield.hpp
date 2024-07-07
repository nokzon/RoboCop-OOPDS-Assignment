#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include "gameinfo.hpp"
#include "robots.hpp"
using namespace std;

class Battlefield {
private:
    GameInfo gameInfo;
    char** battlefield;                 // 2D array representing the battlefield
    vector<Robot*> robots;              // List of robots

public:
    Battlefield(GameInfo& gameInfo);    // constructor
    ~Battlefield();                     // destructor

    void addRobot(Robot* robot);
    void updateBattlefield();           // update battlefield with robots
    void outputBattlefield(ostream &out);
    void printBattlefield();
    Robot* findRobotAtPosition(int posY, int posX) const;
    bool hasTwoRobots(int posY, int posX) const;
    Robot* getRobot(int x) { return robots[x]; }
    bool checkOneRobotAlive();
    void upgradeRobot(Robot* oldRobot, const string& newType, ostream &out);
    void replaceRobot(Robot* oldRobot, Robot* newRobot);
    friend ostream &operator<<(ostream &out, Battlefield battlefield) {
        return out;
    }
};

#endif
