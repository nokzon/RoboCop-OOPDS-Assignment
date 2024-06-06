#include "battlefield.h"
#include "robots.h"
#include "gameInfo.h"
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

// check if the given cell has a Robot or not
bool Battlefield::isRobot(int row, int col) {
    if (battlefield[row][col] == 'M')
        return (true);
    else 
        return (false);
}

void Battlefield::printBattlefield(GameInfo& gameInfo) {
    int i, j;
    printf("    ");

    for (i = 0; i < gameInfo.N; i++) {
        if (i < 10) {cout << i << "  ";}
        else if (i >= 10) {cout << i << " ";}
    }

    printf("\n");

    for (i = 0; i < gameInfo.M; i++) {
        if (i < 10) {cout << i << "   ";}
        else if (i >= 10) {cout << i << "  ";}

        for (j = 0; j < gameInfo.N; j++)
            printf("%c  ", battlefield[i][j]);
        printf("\n");
    }
    return;        
}

// destructor implementation
Battlefield::~Battlefield() {
    for (int i = 0; i <= gameInfo.M; i++) {
        delete[] battlefield[i];
    }
    delete[] battlefield;
}
