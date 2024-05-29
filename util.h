#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
using namespace std;

// information gotten after parsing the initial game text file
struct gameInfo {
    int robotNo;        // Number of Robots
    string robotType;   // Type of robot
    string robotName;   // Name of robot 
    int row;            // robot coordinate row (ROW column)
    int column;         // robot coordinate column (row COLUMN)
    int M;              // row 
    int N;              // column
    int steps;          
};

void readFiles();
gameInfo parseGameGridInfo(const string& line);
int parseStepsInfo(const string& line);
int parseRobotNoInfo(const string& line);
void printGrid(int &userRows, int &userColumns);
void printGameInfo(const gameInfo& info);

class Robot{
public:
    // TODO: All the functions;
};

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
