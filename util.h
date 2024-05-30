#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
using namespace std;

// stuct solely to store robot details
struct RobotInfo {
    string type;
    string name;
    string positionX;   // put as string first to get random, later when doing code make it int
    string positionY;
};

// information gotten after parsing the initial game text file
struct GameInfo {
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    RobotInfo* robots;  // Pointer to array for robot info        
};

// Function prototypes
GameInfo parseGameGridInfo(const string& line);
int parseStepsInfo(const string& line);
int parseRobotCountInfo(const string& line);
RobotInfo parseRobotInfo(const string& line);
void addRobot(GameInfo &info, const RobotInfo &robot);
GameInfo readFile(const string &filename);
void printGameInfo(const GameInfo &info);
void printGrid(int fieldRows, int fieldCol);

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
