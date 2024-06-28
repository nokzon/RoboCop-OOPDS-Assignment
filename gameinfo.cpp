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

// Function that reads tne input file and parses the information
void GameInfo::readFile(const string& fileName) {

    // Read files input.txt
    ifstream myFile(fileName);
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

            for (int i = 0; i < this->robotCount; ++i) {
                getline(myFile, myLine);
                this->robots[i] = parseRobotInfo(myLine, *this); // Store the created robot object in the robots array
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
    this->robots = new Robot*[this->robotCount]; // Allocate memory for the robots array
    
}

// Parse the information of each robot
Robot* GameInfo::parseRobotInfo(const std::string& line, const GameInfo& gameInfo) {
    stringstream s(line);
    string type, name, posYStr, posXStr;
    int posY, posX;
    s >> type >> name >> posYStr >> posXStr;

    if (posYStr.at(0) == 'r' || posXStr.at(0) == 'r') {
        posY = rand() % gameInfo.M; // generate a random number between 0 and M-1
        posX = rand() % gameInfo.N; // generate a random number between 0 and N-1
    } else {
        posY = stoi(posYStr);
        posX = stoi(posXStr);
    }

    if (type == "MadBot"){
        Robot* r = new MadBot(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "RoboCop"){
        Robot* r = new RoboCop(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "Terminator"){
        Robot* r = new Terminator(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "TerminatorRoboCop"){
        Robot* r = new TerminatorRoboCop(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "BlueThunder"){
        Robot* r = new BlueThunder(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "RoboTank"){
        Robot* r = new RoboTank(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type == "UltimateRobot"){
        Robot* r = new UltimateRobot(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    else if (type != "MadBot"){
        Robot* r = new MadBot(type, name, posY, posX);
        r->printInfo();
        return r;
    }
    // TODO: It will call the specific robot class for instance then it will slowly inherit all the way up to base class. 

    else{
        throw runtime_error("Unknown robot type!");
    }
}

// Function to print the contents of a gameInfo object
void GameInfo::printGameInfo() {
    cout << "Grid Dimensions: " << this->M << " by " << this->N << endl;
    cout << "Steps: " << this->steps << endl;
    cout << "Number of Robots: " << this->robotCount << endl;
}

// Function to delete robot objects
// void GameInfo::deleteRobots() {
//     for (int i = 0; i < this->robotCount; ++i){
//         delete this->robots[i];
//     }
//     delete[] this->robots;
// }
