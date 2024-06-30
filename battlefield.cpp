#include "battlefield.hpp"
#include "robots.hpp"
#include "gameinfo.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std; 

// constructor implementation
Battlefield::Battlefield(GameInfo& gameInfo) : gameInfo(gameInfo) {
    // dynamically allocate memory for the 2D array
    battlefield = new char*[gameInfo.M + 1];
    for (int i = 0; i <= gameInfo.M; i++) {
        battlefield[i] = new char[gameInfo.N + 1];
        for (int j = 0; j <= gameInfo.N; j++) {
            battlefield[i][j] = '.';    // initialize all cells to '.'
        }
    }
}

// destructor implementation
Battlefield::~Battlefield() {
    for (int i = 0; i <= gameInfo.M; i++) {
        delete[] battlefield[i];
    }
    delete[] battlefield;
}

void Battlefield::addRobot(Robot* robot) {
    robots.push_back(robot);
}

// In battlefield.cpp
void Battlefield::updateBattlefield() {
    // Reset the battlefield to empty state
    for (int i = 0; i < gameInfo.M; ++i) {
        for (int j = 0; j < gameInfo.N; ++j) {
            battlefield[i][j] = '.';
        }
    }

    // Place robots on the battlefield
    for (Robot* robot : robots) {
        int posY = robot->getPosY();
        int posX = robot->getPosX();
        char symbol = robot->getSymbol();
    
        // Check boundaries
        if (posY >= 0 && posY < gameInfo.M && posX >= 0 && posX < gameInfo.N) {
            if (robot->isAlive()) {
                battlefield[posY][posX] = symbol;
            }
        } else {
            // Handle out-of-bounds error if necessary
            cerr << "Robot position out of bounds: (" << posY << ", " << posX << ")" << endl;
        }
    }
}

Robot* Battlefield::findRobotAtPosition(int posY, int posX) const {
    for (Robot* robot : robots) {
        if (robot->getPosY() == posY && robot->getPosX() == posX) {
            if (robot->isAlive()) {
                return robot;
            }
        }
    }
    return nullptr;
}

// bool Battlefield::hasTwoRobots(int posY, int posX) const {
//     int count;
//     for (Robot* robot : robots) {
//         if (robot->getPosY() == posY && robot->getPosX() == posX) {
//             count++;
//         }
//     }
//     if (count > 1)
//         return true;
//     else
//         return false;
// }

void Battlefield::printBattlefield() {
    updateBattlefield(); // Update the battlefield with current robot positions

    std::cout << "   ";
    for (int i = 0; i < gameInfo.N; ++i) {
        std::cout << std::setw(3) << i; // Print column numbers
    }
    std::cout << "\n";

    for (int i = 0; i < gameInfo.M; ++i) {
        std::cout << std::setw(3) << i; // Print row numbers
        for (int j = 0; j < gameInfo.N; ++j) {
            Robot* currentRobot = findRobotAtPosition(i, j);
            if (currentRobot) {
                std::cout << std::setw(3) << currentRobot->getSymbol(); // Print robot symbol
            } else {
                std::cout << std::setw(3) << battlefield[i][j]; // Print empty cell
            }
        }
        std::cout << "\n";
    }
}

bool Battlefield::checkOneRobotAlive()
{
    int robotAlive = 0;
    for (int i = 0; i < robots.size(); i++) {
        if (robots[i]->getLives() > 0) {
            robotAlive++;
        }
    }
    if (robotAlive + 1 == gameInfo.getRobotCount()) {
        return true;
    }
    return false;
}