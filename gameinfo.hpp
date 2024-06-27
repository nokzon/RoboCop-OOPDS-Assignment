#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include "robots.hpp"
using namespace std;

// Information gotten after parsing the initial game text file
class GameInfo {
public:
    int M;              // row, y
    int N;              // column, x
    int steps;
    int robotCount;     // Number of Robots  
    Robot** robots;
    // robotInfo* robots;  // Pointer to array for robot info  

    friend class Battlefield;
    friend class Robot;

    void readFile(const string& fileName);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    Robot* parseRobotInfo(const string& line, const GameInfo& gameInfo);
    void printGameInfo();
    void deleteRobots();
};

#endif // GAMEINFO_HPP