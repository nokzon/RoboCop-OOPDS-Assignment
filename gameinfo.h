#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include "robots.h"
using namespace std;

// Information gotten after parsing the initial game text file
class GameInfo {
public:
    int M;              // row, y
    int N;              // column, x
    int steps;
    int robotCount;     // Number of Robots  
    Robot** robots;

    friend class Battlefield;
    friend class Robot;

    void readFile(const string& filename);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    void printGameInfo();
    void deleteRobots();
    Robot* parseRobotInfo(const string& line, const GameInfo& gameInfo);
};

#endif // GAMEINFO_H