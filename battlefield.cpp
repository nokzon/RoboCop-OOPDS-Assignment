#include "battlefield.hpp"
#include "robots.hpp"
#include "gameinfo.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
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

void Battlefield::outputBattlefield(ostream &out) {
    updateBattlefield(); // Update the battlefield with current robot positions

    out << "   ";
    for (int i = 0; i < gameInfo.N; ++i) {
        out << std::setw(3) << i; // Print column numbers
    }
    out << "\n";

    for (int i = 0; i < gameInfo.M; ++i) {
        out << std::setw(3) << i; // Print row numbers
        for (int j = 0; j < gameInfo.N; ++j) {
            Robot* currentRobot = findRobotAtPosition(i, j);
            if (currentRobot) {
                out << std::setw(3) << currentRobot->getSymbol(); // Print robot symbol
            } else {
                out << std::setw(3) << battlefield[i][j]; // Print empty cell
            }
        }
        out << "\n";
    }
}

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

// Upgrades robot when they get 3 kills
void Battlefield::upgradeRobot(Robot* oldRobot, const string& newType, ostream &out) {
    Robot* newRobot = nullptr;

    // Create the new robot based on the new type
    if (newType == "TerminatorRoboCop") {
        newRobot = new TerminatorRoboCop("TerminatorRoboCop", oldRobot->getRobotName(), oldRobot->getPosY(), oldRobot->getPosX());
    }
    if (newType == "MadBot") {
        newRobot = new MadBot("MadBot", oldRobot->getRobotName(), oldRobot->getPosY(), oldRobot->getPosX());
    }
    if (newType == "RoboTank") {
        newRobot = new RoboTank("RoboTank", oldRobot->getRobotName(), oldRobot->getPosY(), oldRobot->getPosX());
    }
    if (newType == "UltimateRobot") {
        newRobot = new UltimateRobot("UltimateRobot", oldRobot->getRobotName(), oldRobot->getPosY(), oldRobot->getPosX());
    }
    if (newRobot) {
        // Copy attributes from old robot to new robot
        oldRobot->copyAttributesTo(newRobot);
        // Replace the old robot with the new robot in the vector
        replaceRobot(oldRobot, newRobot);

        // Example of using new robot's functions after upgrade
        if (TerminatorRoboCop* newTerminator = dynamic_cast<TerminatorRoboCop*>(newRobot)) {
            newTerminator->look(out, 0, 0);
            newTerminator->move(out);
            newTerminator->step(out);
            newTerminator->fire(out);
        }
        if (MadBot* newMadBot = dynamic_cast<MadBot*>(newRobot)) {
            newMadBot->fire(out);
        }
        if (RoboTank* newRoboTank = dynamic_cast<RoboTank*>(newRobot)) {
            newRoboTank->fire(out);
        }
        if (UltimateRobot* newUltimateRobot = dynamic_cast<UltimateRobot*>(newRobot)) {
            newUltimateRobot->look(out, 0, 0);
            newUltimateRobot->move(out);
            newUltimateRobot->step(out);
            newUltimateRobot->fire(out);
        }
        else {
            cerr << "Error: Could not cast to the desired robot type." << endl;
        }
    }
    else {
        cerr << "Error: Unknown robot type for upgrade." << endl;
    }
}

// This replaces old robots with new ones
void Battlefield::replaceRobot(Robot* oldRobot, Robot* newRobot) {
    auto it = find(gameInfo.robotVector.begin(), gameInfo.robotVector.end(), oldRobot);
    if (it != gameInfo.robotVector.end()) {
        *it = newRobot;
        delete oldRobot;
    }
    else {
        cerr << "Error: Could not find the old robot in the vector." << endl;
    }
    // delete oldRobot;
}