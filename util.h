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
public:
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    robot** robots;
    // robotInfo* robots;  // Pointer to array for robot info  

public:
    // friend class RobotInfo; NOT NEEDED?
    friend class Battlefield;

    void readFile(const string& filename);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    void printGameInfo();
    void deleteRobots();

};

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
