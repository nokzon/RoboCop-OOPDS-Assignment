#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include "robots.h"
using namespace std;

// stuct solely to store robot details
// struct RobotInfo {
//     string type;
//     string name;
//     string positionX;   // is a string to be able to get random, convert to int later
//     string positionY;
// };

// information gotten after parsing the initial game text file
struct gameInfo {
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    robot** robots;
    // robotInfo* robots;  // Pointer to array for robot info        
};

// Function prototypes
gameInfo parseGameGridInfo(const string& line);
int parseStepsInfo(const string& line);
int parseRobotCountInfo(const string& line);
// RobotInfo parseRobotInfo(const string& line);
// void addRobot(GameInfo &info, const RobotInfo &robot);
gameInfo readFile(const string &filename);
void printGameInfo(const gameInfo &info);
void printGrid(int fieldRows, int fieldCol);
robot* parseRobotInfo(const string& line);

#endif
