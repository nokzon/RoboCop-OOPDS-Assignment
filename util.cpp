#include "util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function prototypes
gameInfo parseGameGridInfo(const string& line);
int parseStepsInfo(const string& line);
int parseRobotCountInfo(const string& line);

// to test if the returned parameters are correct
void printGameInfo(const gameInfo& info);

// readFiles function, it reads the content from input.txt and takes in the needed contents
void readFiles() {
    // gameInfo object to store the parsed information
    gameInfo info;

    // Read files input.txt
    ifstream myFile("input.txt");
    string myLine;

    if (!myFile) {
        cerr << "Error: CouldCountt open input file" << endl;
        return;
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

            cout << "test: " << info.robotCount << endl;

            for (int i = 0; i < info.robotCount; i++) {
                getline(myFile, myLine);
                // cout << "hi" << endl;
                string type, name;
                string x, y;
                stringstream ss(myLine);

                ss >> type >> name >> x >> y;
                cout << type << " " << name << " " << x << " " << y << endl;
                // TODO: add variables into array
            }
        }

        

        // Skip empty lines or lines that don't contain relevant information
        // if (myLine.find_firstCountt_of(' ') == string::npos) {
        //     continue; // Skip empty lines
        // }
        // else {
        //     cerr << "Error: Unrecognized line in input file: " << myLine << endl;
        // }
    }

    // Print the parsed information to verify it
    printGameInfo(info);

    // Close file to prevent wasting memory resources
    myFile.close();
}


// Parse the grid information from the first line of the text file
gameInfo parseGameGridInfo(const string& line) {
    gameInfo info;

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
int parseRoboCountInfo(const string& line) {
    return stoi(line.substr(8)); // Extract the number of robots from the line
}

// Parse the information of each robot
robotInfo parseRobotInfo(const string& line) {
    stringstream s(line);
    robotInfo robot;
    s >> robot.type >> robot.name >> robot.positionX >> robot.positionY;
    return robot;
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
void printGameInfo(const gameInfo& info) {
    cout << "Grid Dimensions: " << info.M << " by " << info.N << endl;
    cout << "Steps: " << info.steps << endl;
    cout << "Number of Robots: " << info.robotCount << endl;
}
