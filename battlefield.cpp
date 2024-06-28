#include "battlefield.hpp"
#include "robots.hpp"
#include "gameinfo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
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

// update battlefield with robots
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
        
        // Check boundaries
        if (posY >= 0 && posY < gameInfo.M && posX >= 0 && posX < gameInfo.N) {
            battlefield[posY][posX] = robot->getSymbol();
        } else {
            // Handle out-of-bounds error if necessary
            cerr << "Robot position out of bounds: (" << posY << ", " << posX << ")" << endl;
        }
    }
}

void Battlefield::printBattlefield(GameInfo& gameInfo) {
    updateBattlefield(); // Update the battlefield with current robot positions

    std::cout << "    ";
    for (int i = 0; i < gameInfo.N; ++i) {
        std::cout << std::setw(3) << i; // Print column numbers
    }
    std::cout << "\n";

    for (int i = 0; i < gameInfo.M; ++i) {
        std::cout << std::setw(3) << i; // Print row numbers
        for (int j = 0; j < gameInfo.N; ++j) {
            std::cout << std::setw(3) << battlefield[i][j]; // Print battlefield cells
        }
        std::cout << "\n";
    }
}