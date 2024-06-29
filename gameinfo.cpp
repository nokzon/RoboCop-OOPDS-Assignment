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
        r = new MadBot(type, name, posY, posX);
    }
    else {
        throw runtime_error("Unknown robot type!");
    }

    r->printInfo();
    robotVector.push_back(r); // Store robot pointer in the vector
    robotStatus(r); // Pass robot object to then be used and get name from class
    return r;
}

// Create a vector pair to store the name and lives of each robot
void GameInfo::robotStatus(Robot* robot){
    robotStatusPair.push_back(make_pair(robot->getName(), 3));
}
// TODO: After doing simulation loop make sure the name calling is correct. We might want to store the entire information of robots instead of just the name
// everytime check if robot still has live, if not then use a destructor or something to delete the robot and remove them from this list.

void GameInfo::printRobotStatus(){
    for (size_t i = 0; i < robotStatusPair.size(); ++i){
        cout << "Pair " << i+1 << ": ";
        cout << robotStatusPair[i].first << " " << robotStatusPair[i].second << endl;
    }
}

// Then create an empty queue that will add robots in if they get hit
void GameInfo::waitingRobots(string& name){
    waitingStatusRobot.push_back(name);
}
// TODO: In simulation loop, check if robot's still alive, if so then only add it to this vector. Robots that are in this list will be respawned into the 
// battlefield when it's their turn.

// Function to print the contents of a gameInfo object
void GameInfo::printGameInfo() {
    cout << "Grid Dimensions: " << this->M << " by " << this->N << endl;
    cout << "Steps: " << this->steps << endl;
    cout << "Number of Robots: " << this->robotCount << endl;
}
