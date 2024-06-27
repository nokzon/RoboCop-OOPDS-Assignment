#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "gameinfo.hpp"
#include "robots.hpp"
using namespace std;

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

#endif
