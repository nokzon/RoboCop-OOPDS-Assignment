#include "util.h"
#include "robots.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function that reads tne input file and parses the information
void GameInfo::readFile(const string& filename) {

    // Read files input.txt
    ifstream myFile("input.txt");
    string myLine;

    if (!myFile) {
        cerr << "Error: Couldn't open input file" << endl;
        exit(1);
    }

    while (getline(myFile, myLine)) {
        // Checks the first line for keywords using stringstream
        if (myLine.find("M by N: ") != string::npos) {
            parseGameGridInfo(myLine);
        }
        // Checks for second line for keywords using stringstream
        if (myLine.find("Steps: ") != string::npos) {
            parseStepsInfo(myLine);
        }
        // Checks for second line for keywords using stringstream
        if (myLine.find("Robots: ") != string::npos) {
            parseRobotCountInfo(myLine);
            // info.robots = new RobotInfo[info.robotCount];   // Allocate memory for robots based on robot Count

            for (int i = 0; i < this->robotCount; ++i) {
                getline(myFile, myLine);
                parseRobotInfo(myLine);
            }
        }
    }
    // Close file to prevent wasting memory resources
    myFile.close();
}


// Parse the grid information from the first line of the text file
void GameInfo::parseGameGridInfo(const string& line) {
    stringstream s(line);
    string dummy;
    s >> dummy >> dummy >> dummy >> this->M >> this->N;
}


// Parse the number of steps from the input line    
void GameInfo::parseStepsInfo(const string& line) {
    this->steps = stoi(line.substr(7)); // Extract the number of steps from the line
}

// Parse the number of robots from the input line
void GameInfo::parseRobotCountInfo(const string& line) {
    this->robotCount = stoi(line.substr(8)); // Extract the number of robots from the line
}

// Parse the information of each robot
robot* parseRobotInfo(const string& line) {
    stringstream s(line);
    string type, name, posY, posX;
    s >> type >> name >> posY >> posX;

    if (type == "Madbot"){
        robot* r = new madBot(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type != "Madbot"){
        robot* r = new madBot(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    // TODO: It will call the specific robot class for instance then it will slowly inherit all the way up to base class. 

    else{
        throw runtime_error("Unknown robot type!");
    }
}


// Printing grid function
// void GameInfo::printGrid(int &fieldRows, int &fieldCol) {
//     fieldRows = this->M;
//     cout << endl;
//     cout << " ";
//     int i = 1, j;

//     // Loop that outputs top row of column numbers
//     for (j = 0; j <= 4 * fieldCol; j++) {
//         if (j % 4 == 2) {
//             cout << i++;
//         }
//         else {
//             cout << " ";
//         }
//     }
//     cout << endl;

//     // Loop to output the entire grid
//     for (i = 0; i <= 2 * fieldRows; i++) {
//         // Print grid numbers on the left side
//         if (i % 2 != 0) {
//             cout << (i / 2) + 1;
//         }
//         else {
//             cout << " ";
//         }

//         // Loop to print all rows of the grid
//         for (j = 0; j <= 2 * fieldCol; j++) {
//             if (i % 2 == 0) {
//                 if (j == 0) {
//                     cout << " ";
//                 }
//                 if (j % 2 == 0) {
//                     cout << " ";
//                 }
//                 else {
//                     cout << "---";
//                 }
//             }
//             else {
//                 if (j % 2 == 0)
//                     cout << "|";
//                 else cout << "   ";
//             }
//         }

//         // Print row numbers on the right side
//         if (i % 2 != 0) {
//             cout << (i / 2) + 1;
//         }
//         cout << endl;
//     }

//     // Outputs bottom row of the column numbers
//     cout << " ";
//     for (j = 0, i = 1; j <= 4 * fieldCol; j++) {
//         if (j % 4 == 2) {
//             cout << i++;
//         }
//         else {
//             cout << " ";
//         }
//     }
//     cout << endl;
// 

// Function to print the contents of a gameInfo object
void GameInfo::printGameInfo() {
    cout << "Grid Dimensions: " << this->M << " by " << this->N << endl;
    cout << "Steps: " << this->steps << endl;
    cout << "Number of Robots: " << this->robotCount << endl;

    // Redundant stuff lol
    // for (int i = 0; i < this->robotCount; i++){
    //     this->robots[i]->printInfo();
    // }
    // for (int i = 0; i < info.robotCount; ++i) {
    //     cout << "Robot " << (i + 1) << ": " << info.robots[i].type << " " << info.robots[i].name 
    //          << " at (" << info.robots[i].positionX << ", " << info.robots[i].positionY << ")" << endl;
    // }
}

// Function to delete robot objects
// void GameInfo::deleteRobots() {
//     for (int i = 0; i < this->robotCount; ++i){
//         delete this->robots[i];
//     }
//     delete[] this->robots;
// }


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
        if (i < 10) {printf("%d  ", i);}
        else if (i >= 10) {printf("%d ", i);}
    }

    printf("\n");

    for (i = 0; i < gameInfo.M; i++) {
        if (i < 10) {printf("%d   ", i);}
        else if (i >= 10) {printf("%d  ", i);}

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