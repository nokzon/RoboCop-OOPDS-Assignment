#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "gameInfo.h"
#include "robots.h"
using namespace std;

class Battlefield {
private:
    GameInfo gameInfo;
    char** battlefield;                 // 2D array representing the battlefield

public:
    Battlefield(GameInfo& gameInfo);    // constructor
    ~Battlefield();                     // destructor
    bool isRobot(int row, int col);     // check if cell has robot or not
    void printBattlefield(GameInfo& gameInfo);
};

// Function prototypes
// void addRobot(GameInfo &info, const RobotInfo &robot);
robot* parseRobotInfo(const string& line); // weird


#endif
