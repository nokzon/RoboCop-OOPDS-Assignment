#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "robots.h"
using namespace std;

// Redundant(?)
// Class that stores robot details
// class RobotInfo {
// private:
//     string type;
//     string name;
//     int positionX;
//     int positionY;

// public:
//     friend class GameInfo;

//     // void parseRobotInfo(const string& line);
// };

// Information gotten after parsing the initial game text file
class GameInfo {
private:
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    robot** robots;
    // robotInfo* robots;  // Pointer to array for robot info  

public:
    friend class RobotInfo;

    void readFile(const string& filename);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    void printGameInfo();
    void printGrid();
    void deleteRobots();
};

// Function prototypes
// void addRobot(GameInfo &info, const RobotInfo &robot);
robot* parseRobotInfo(const string& line); // weird


#endif
