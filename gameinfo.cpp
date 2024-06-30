#include "battlefield.hpp"
#include "robots.hpp"
#include "gameinfo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
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
    stringstream s(line);
    string dummy;
    s >> dummy >> this->steps;
}

// Parse the number of robots from the input line
void GameInfo::parseRobotCountInfo(const string& line) {
    stringstream s(line);
    string dummy;
    s >> dummy >> this->robotCount;
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

    Robot* r = nullptr;

    if (type == "MadBot"){
        r = new MadBot(type, name, posY, posX);
    }
    else if (type == "RoboCop"){
        r = new RoboCop(type, name, posY, posX);
    }
    else if (type == "Terminator"){
        r = new Terminator(type, name, posY, posX);
    }
    else if (type == "TerminatorRoboCop"){
        r = new TerminatorRoboCop(type, name, posY, posX);
    }
    else if (type == "BlueThunder"){
        r = new BlueThunder(type, name, posY, posX);
    }
    else if (type == "RoboTank"){
        r = new RoboTank(type, name, posY, posX);
    }
    else if (type == "UltimateRobot"){
        r = new UltimateRobot(type, name, posY, posX);
    }
    else if (type != "MadBot"){
        Robot* r = new MadBot(type, name, posY, posX);
    }

    if (r) {
        r->printInfo();
        robotVector.push_back(r); // Store robot object in the vector
        robotLives(r); // Pass robot object o then be used and get name from class
        return r;
    }
    else {
        throw runtime_error("Unknown robot type!");
    }
}

// Create a vector pair to store the name and lives of each robot
void GameInfo::robotLives(Robot* robot){
    robotLivesPair.push_back(make_pair(robot->getName(), 3));
}

// Function to check if a robot exists and deduct its lives
// void GameInfo::checkRobotLives(const string& name){
//     // Define the lambda function
//     auto findRobotByName = [&name](const pair<string, int>& p) {
//         return p.first == name;
//     };

//     auto it = find_if(robotLivesPair.begin(), robotLivesPair.end(), findRobotByName);

//     if (it != robotLivesPair.end()) {
//         if (it->second >= 0) {
//             it->second -= 1;
//         }
//         else {
//             cout << "Robot " << name << " has no lives remaining." << endl;
//         }
//     }
//     else {
//         cerr << "Error: Robot " << name << " not found in robotLivesPair vector." << endl;
//     }
// }

void GameInfo::printRobotStatus(){
    for (size_t i = 0; i < robotLivesPair.size(); ++i){
        cout << "Pair " << i+1 << ": ";
        cout << robotLivesPair[i].first << " " << robotLivesPair[i].second << endl;
    }
}

// Then create an empty queue that will add robots in if they get hit
void GameInfo::waitingRobots(string& name){
    waitingStatusRobot.push_back(name);
}

// Upgrades robot when they get 3 kills
void GameInfo::upgradeRobot(Robot* oldRobot, const string& newType) {
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
    } else {
        cerr << "Error: Unknown robot type for upgrade." << endl;
    }
}

// This replaces old robots with new ones
void GameInfo::replaceRobot(Robot* oldRobot, Robot* newRobot) {
    auto it = find(robotVector.begin(), robotVector.end(), oldRobot);
    if (it != robotVector.end()) {
        *it = newRobot;
    }
    delete oldRobot;
}

// Function to print the contents of a gameInfo object
void GameInfo::printGameInfo() {
    cout << "Grid Dimensions: " << this->M << " by " << this->N << endl;
    cout << "Steps: " << this->steps << endl;
    cout << "Number of Robots: " << this->robotCount << endl;
}
