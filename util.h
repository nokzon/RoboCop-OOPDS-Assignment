#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "robots.h"
using namespace std;

// Class that stores robot details
class RobotInfo {
private:
    string type;
    string name;
    int positionX;
    int positionY;

public:
    friend class GameInfo;

    void parseRobotInfo(const string& line);
};

// Class that stores the game information
class GameInfo {
private:
    int M;              // Row 
    int N;              // Column
    int steps;
    int robotCount;
    RobotInfo* robots;  // Pointer to array for robot info

public:
    friend RobotInfo;

    void readFile(const string& filename);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    void printGameInfo();
};

// Function prototypes
// void addRobot(GameInfo &info, const RobotInfo &robot);

class MovingRobot : public Robot{
    // TODO: All the functions;
};

class ShootingRobot : public Robot{
    // TODO: All the functions;
};

class SeeingRobot : public Robot{
    //TODO: All the functions;
};

class SteppingRobot : public Robot{
    //TODO: All the functions;
};

class RoboCop : public MovingRobot, public SeeingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class Terminator : public MovingRobot, public SeeingRobot, public SteppingRobot{
    //TODO: All the functions;
};

class TerminatorRoboCop : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class BlueThunder : public ShootingRobot{
    //TODO: All the functions;
};

class Madbot : public ShootingRobot{
    //TODO: All the functions;
};

class RoboTank : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class UltimateRobot : public MovingRobot, public SteppingRobot, public SeeingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class CustomRobot{
    //TODO: All the functions;
};

#endif
