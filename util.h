#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "robots.h"
using namespace std;

// Redundant(?)
// Class that stores robot details
// class RobotInfo {
// private:
//     string type;
//     string name;
//     int positionX;
//     int positionY;

// public:
//     friend class GameInfo;

//     // void parseRobotInfo(const string& line);
// };

// Information gotten after parsing the initial game text file
class GameInfo {
public:
    int M;              // row 
    int N;              // column
    int steps;
    int robotCount;     // Number of Robots  
    robot** robots;
    // robotInfo* robots;  // Pointer to array for robot info  

public:
    // friend class RobotInfo; NOT NEEDED?
    friend class Battlefield;

    void readFile(const string& filename);
    void parseGameGridInfo(const string& line);
    void parseStepsInfo(const string& line);
    void parseRobotCountInfo(const string& line);
    void printGameInfo();
    void deleteRobots();

};

class Battlefield {
private:
    GameInfo& gameInfo; // Reference to GameInfo

public:
    char** battlefield;

    Battlefield(GameInfo& gameInfo) : gameInfo(gameInfo) {
        battlefield = new char*[gameInfo.M + 1];
        for (int i = 0; i <= gameInfo.M; i++) {
            battlefield[i] = new char[gameInfo.N + 1];
            for (int j = 0; j <= gameInfo.N; j++) {
                battlefield[i][j] = '.';
            }
        }
    }

    // Function to check if the given cell has a Robot or not
    bool isRobot(int row, int col) {
        if (battlefield[row][col] == 'M')
            return (true);
        else 
            return (false);
    }

    void printBattlefield(GameInfo& gameInfo) {
        int i, j;
        printf("    ");

        for (i = 0; i < 15; i++) {
            if (i < 10) {printf("%d  ", i);}
            else if (i >= 10) {printf("%d ", i);}
        }

        printf("\n\n");

        for (i = 0; i < 15; i++) {
            if (i < 10) {printf("%d   ", i);}
            else if (i >= 10) {printf("%d  ", i);}

            for (j = 0; j < 15; j++)
                printf("%c  ", battlefield[i][j]);
            printf("\n");
        }
        return;        
    }
    

    ~Battlefield() {
        for (int i = 0; i <= gameInfo.M; i++) {
            delete[] battlefield[i];
        }
        delete[] battlefield;
    }    
};

// Function prototypes
// void addRobot(GameInfo &info, const RobotInfo &robot);
robot* parseRobotInfo(const string& line); // weird


#endif
