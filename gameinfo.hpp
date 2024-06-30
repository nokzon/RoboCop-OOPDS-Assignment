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
    
    vector<Robot*> robotVector;
    vector<pair<string, int>> robotLivesPair;
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
    void robotLives(Robot* robot);
    void checkRobotLives(const string& name);
    void printRobotStatus();
    void waitingRobots(string& name);
    void upgradeRobot(Robot* oldRobot, const string& newType);
    void replaceRobot(Robot* oldRobot, Robot* newRobot);
    int getRobotCount() { return robotCount; }
};

#endif // GAMEINFO_HPP
