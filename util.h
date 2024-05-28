#include <iostream>
#include <string>
using namespace std;
#ifndef UTIL_H
#define UTIL_H

void printGrid(int &userRows, int &userColumns);

struct robotInfo {
    int robotNo;        // Number of Robots
    string robotType;   // Type of robot
    string robotName;   // Name of robot 
    int row;            // robot coordinate row (ROW column)
    int column;         // robot coordinate column (row COLUMN)
};

struct battlefield {
    int M;  // row
    int N;  // column
    int steps;  
};

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
