#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP

#include <string>
#include <vector>
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
    string type, name, posYStr, posXStr;
    // robotInfo* robots;  // Pointer to array for robot info  
    
    vector<pair<string, int>> robotStatusPair;
    vector<string> waitingStatusRobot;

    friend class Battlefield;
    friend class Robot;

    void readFile(const string& fileName);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    Robot* parseRobotInfo(const string& line, const GameInfo& gameInfo);
    void printGameInfo();
    void deleteRobots();
    void robotStatus(string& name);
    void printRobotStatus();
    void waitingRobots(string& name);
};

#endif // GAMEINFO_HPP
