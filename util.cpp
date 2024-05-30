#include "util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function that reads tne input file and parses the information
GameInfo readFile(const string& filename) {

    // Read files input.txt
    ifstream myFile("input.txt");
    GameInfo info;  // gameInfo object to store the parsed information
    string myLine;

    if (!myFile) {
        cerr << "Error: Couldn't open input file" << endl;
        exit(1);
    }

    while (getline(myFile, myLine)) {
        // Checks the first line for keywords using stringstream
        if (myLine.find("M by N: ") != string::npos) {
            info = parseGameGridInfo(myLine);
        }
        // Checks for second line for keywords using stringstream
        if (myLine.find("Steps: ") != string::npos) {
            info.steps = parseStepsInfo(myLine);
        }
        // Checks for second line for keywords using stringstream
        if (myLine.find("Robots: ") != string::npos) {
            info.robotCount = parseRobotCountInfo(myLine);
            // info.robots = new RobotInfo[info.robotCount];   // Allocate memory for robots based on robot Count

            for (int i = 0; i < info.robotCount; ++i) {
                getline(myFile, myLine);
                info.robots[i] = parseRobotInfo(myLine);
            }
        }
    }
    // Close file to prevent wasting memory resources
    myFile.close();
    return info;
}


// Parse the grid information from the first line of the text file
GameInfo parseGameGridInfo(const string& line) {
    GameInfo info;

    stringstream s(line);
    string dummy;
    s >> dummy >> dummy >> dummy >> info.M >> info.N;

    return info;
}


// Parse the number of steps from the input line
int parseStepsInfo(const string& line) {
    return stoi(line.substr(7)); // Extract the number of steps from the line
}


// Parse the number of robots from the input line
int parseRobotCountInfo(const string& line) {
    return stoi(line.substr(8)); // Extract the number of robots from the line
}

// Parse the information of each robot
Robot* parseRobotInfo(const string& line) {
    stringstream s(line);
    string type, name;
    int row, column;
    s >> type >> name >> row >> column;

    if (type == "Madbot"){
        return new madBot(name, row, column);
    }
    else if (type == "RoboTank"){
        return new roboTank(name, row, column);
    }

    throw runtime_error("Unknown robot type!");
}


// Printing grid function
void printGrid(int &fieldRows, int &fieldCol) {
    cout << endl;
    cout << " ";
    int i = 1, j;

    // Loop that outputs top row of column numbers
    for (j = 0; j <= 4 * fieldCol; j++) {
        if (j % 4 == 2) {
            cout << i++;
        }
        else {
            cout << " ";
        }
    }
    cout << endl;

    // Loop to output the entire grid
    for (i = 0; i <= 2 * fieldRows; i++) {
        // Print grid numbers on the left side
        if (i % 2 != 0) {
            cout << (i / 2) + 1;
        }
        else {
            cout << " ";
        }

        // Loop to print all rows of the grid
        for (j = 0; j <= 2 * fieldCol; j++) {
            if (i % 2 == 0) {
                if (j == 0) {
                    cout << " ";
                }
                if (j % 2 == 0) {
                    cout << " ";
                }
                else {
                    cout << "---";
                }
            }
            else {
                if (j % 2 == 0)
                    cout << "|";
                else cout << "   ";
            }
        }

        // Print row numbers on the right side
        if (i % 2 != 0) {
            cout << (i / 2) + 1;
        }
        cout << endl;
    }

    // Outputs bottom row of the column numbers
    cout << " ";
    for (j = 0, i = 1; j <= 4 * fieldCol; j++) {
        if (j % 4 == 2) {
            cout << i++;
        }
        else {
            cout << " ";
        }
    }
    cout << endl;
}

// Function to print the contents of a gameInfo object
void printGameInfo(const GameInfo& info) {
    cout << "Grid Dimensions: " << info.M << " by " << info.N << endl;
    cout << "Steps: " << info.steps << endl;
    cout << "Number of Robots: " << info.robotCount << endl;
    for (int i = 0; i < info.robotCount; ++i) {
        cout << "Robot " << (i + 1) << ": " << info.robots[i].type << " " << info.robots[i].name 
             << " at (" << info.robots[i].positionX << ", " << info.robots[i].positionY << ")" << endl;
    }
}
