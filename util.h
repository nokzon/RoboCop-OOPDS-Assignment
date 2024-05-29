#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
using namespace std;

// stuct solely to store robot details
struct robotInfo {
    string type;
    string name;
    int positionX;
    int positionY;
};

// information gotten after parsing the initial game text file
struct gameInfo {
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    Robot* robot;       // Pointer to array for robot info        
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
