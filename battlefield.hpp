#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include <vector>
#include "gameinfo.hpp"
#include "robots.hpp"
using namespace std;

class Battlefield {
private:
    GameInfo gameInfo;
    char** battlefield;                 // 2D array representing the battlefield
    vector<Robot*> robots;              // List of robots

public:
    Battlefield(GameInfo& gameInfo);    // constructor
    ~Battlefield();                     // destructor

    void addRobot(Robot* robot);
    void updateBattlefield();           // update battlefield with robots
    void printBattlefield();
    Robot* findRobotAtPosition(int posY, int posX) const;
};

#endif
