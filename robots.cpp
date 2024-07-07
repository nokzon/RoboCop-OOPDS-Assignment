#include "robots.hpp"
#include <iostream>
#include <string>
using namespace std;

// ******************************************************************
// BASE CLASS ROBOT
// ******************************************************************
Robot::Robot(const string& type, const string& name, int r, int c) 
    : robotType(type), robotName(name), posY(r), posX(c) {}

// ******************************************************************
// MOVING ROBOT
// ******************************************************************
MovingRobot::MovingRobot(const string& type, const string& name, int r, int c) 
    : Robot(type, name, r, c) {}

void MovingRobot::move(ostream &out)
{
    // Generates a number between -1 to 1, then round them to nearest integer -1, 0, 1
    // Try to move robot in battlefield array, if out of bounds(first/last array, first/last index), generate again
    // Move symbol 'x' and '.'
}

// ******************************************************************
// SHOOTING ROBOT
// ******************************************************************
ShootingRobot::ShootingRobot(const string& type, const string& name, int r, int c) 
    : Robot(type, name, r, c) {}

void ShootingRobot::fire(ostream &out, int x, int y)
{
    // This function targets an element in the battlefield and destroys it if it's not '.'
    // Randomly generates x and y between -10 to 10, if |x| + |y| > 10, or |x| + |y| == 0, generate again
    // Shoots at the x and y coordinate generated relative to the robot's position
}

void ShootingRobot::fire(ostream &out)
{
    // Overloaded function that generates its own numbers to randomly shoot around the map
    // Can further be defined by specific shooting robots that have specific patterns
    // BlueThunder shoots from (0, 1) -> (1, 1) -> (1, 0)
    // MadBot generates between -1 to 1 and shoots
    // RoboTank and UltimateRobot generates between M - 1 to N - 1 and shoots
}

// ******************************************************************
// SEEING ROBOT
// ******************************************************************
SeeingRobot::SeeingRobot(const string& type, const string& name, int r, int c) 
    : Robot(type, name, r, c) {}

void SeeingRobot::look(ostream &out, int x, int y)
{
    // Looks at a specific coordinate on the grid, then reveals a 3x3 area around that coordinate
    // 3x3 area needs to reveal whether parts of it are in battlefield or not, and reveal robot if there's one
}

// ******************************************************************
// STEPPING ROBOT
// ******************************************************************
SteppingRobot::SteppingRobot(const string& type, const string& name, int r, int c) 
    : Robot(type, name, r, c) {}

void SteppingRobot::step(ostream &out)
{
    // If a non-stepping robot moves to a location that has another robot, it'll choose another coordinate to move to (rng)
    // Can check if the moving robot is a stepping robot, then ALLOW it to kill the enemy robot and occupy its space by calling this function
}

// ******************************************************************
// ROBOCOP
// ******************************************************************
RoboCop::RoboCop(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void RoboCop::look(ostream &out, int x, int y)
{
    cout << robotName << " looks around its current position." << endl;  
    out << robotName << " looks around its current position." << endl;
    movableStep.clear();
    movableLocation.clear();

    vector<int> newCoord;
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


    for (int d = 0; d < 8; d++) {

        int newRow = posY + dy[d];
        int newCol = posX + dx[d];

        // Check if the new position is within the battlefield
        if (newRow >= 0 && newRow < gameInfo->M && newCol >= 0 && newCol < gameInfo->N) {    
            newCoord.clear();
            // Check if there's a robot at the new position
            Robot* robot = battlefield->findRobotAtPosition(newRow, newCol);
            if (robot) {
                cout << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                out << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableStep.push_back(newCoord);
            }
            else {
                // cout << "Empty at (" << newRow << ", " << newCol << ")" << endl; // Commented out because it works but is messy
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableLocation.push_back(newCoord);
            }
        }
        else {
            // cout << "(" << newRow << ", " << newCol << ") is out of bounds" << endl; // Commented out, it works but is messy
        }
    }
}

void RoboCop::move(ostream &out) 
{
    int x = rand() % movableLocation.size();
    posY = movableLocation[x][0];
    posX = movableLocation[x][1];

    cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
}

void RoboCop::step(ostream &out)
{
}

void RoboCop::fire(ostream &out)
{
}

void RoboCop::fire(ostream &out, int x, int y) 
{
    if (posY + y < gameInfo->M && posX + x < gameInfo->N) {
        if (posY + y >= 0 && posX + x >= 0) {
            Robot* robot = battlefield->findRobotAtPosition(posY + y, posX + x);
            cout << robotName << " fires at (" << posY + y << ", " << posX + x << ")" << endl;
            out << robotName << " fires at (" << posY + y << ", " << posX + x << ")" << endl;
            if (robot)
            {
                cout << robotName << " hit a robot" << endl;
                out << robotName << " hit a robot" << endl;
                robot->toggleAliveState();
                kills++;
            }
        }
        else {
            cout << robotName << " fires at an empty location." << endl;
            out << robotName << " fires at an empty location." << endl;
        }
    }
    else {
        cout << robotName << " fires at an empty location." << endl;
        out << robotName << " fires at an empty location." << endl;
    }
}

void RoboCop::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// TERMINATOR
// ******************************************************************
Terminator::Terminator(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), SteppingRobot(type, name, r, c) {}

void Terminator::look(ostream &out, int x, int y)
{
    cout << robotName << " looks around its immediate neighbourhood." << endl;
    out << robotName << " looks around its immediate neighbourhood." << endl;
    movableStep.clear();
    movableLocation.clear();
    
    vector<int> newCoord;
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int d = 0; d < 8; d++) {

        int newRow = posY + dy[d];
        int newCol = posX + dx[d];

        // Check if the new position is within the battlefield
        if (newRow >= 0 && newRow < gameInfo->M && newCol >= 0 && newCol < gameInfo->N) {    
            newCoord.clear();
            // Check if there's a robot at the new position
            Robot* robot = battlefield->findRobotAtPosition(newRow, newCol);
            if (robot) {
                cout << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                out << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableStep.push_back(newCoord);
            }
            else {
                // cout << "Empty at (" << newRow << ", " << newCol << ")" << endl; // Commented out, it works but is messy
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableLocation.push_back(newCoord);
            }
        }
        else {
            // cout << "(" << newRow << ", " << newCol << ") is out of bounds" << endl; // Commented out, it works but is messy
        }
    }
}

void Terminator::move(ostream &out) 
{
    if (!(movableStep.empty()))
    {
        int otherRobotPosX, otherRobotPosY;
        int x = rand() % movableStep.size();
        otherRobotPosY = movableStep[x][0];
        otherRobotPosX = movableStep[x][1];

        Robot* robot = battlefield->findRobotAtPosition(otherRobotPosY, otherRobotPosX);
        robot->toggleAliveState();
        // robot->enterQueue();

        posY = movableStep[x][0];
        posX = movableStep[x][1];
        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
    else
    {
        int x = rand() % movableLocation.size();
        posY = movableLocation[x][0];
        posX = movableLocation[x][1];

        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
}

void Terminator::step(ostream &out)
{
    if (!(movableStep.empty()))
    {
        cout << robotName << " steps on a robot" << endl;
        out << robotName << " steps on a robot" << endl;
        kills++;
    }
    else
    {
        cout << robotName << " did not step on a robot" << endl;
        out << robotName << " did not step on a robot" << endl;
    }
}

void Terminator::fire(ostream &out)
{
    cout << robotName << " does not fire" << endl;
    out << robotName << " does not fire" << endl;
}

void Terminator::fire(ostream &out, int x, int y) 
{
}

void Terminator::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// TERMINATOR ROBOCOP
// ******************************************************************
TerminatorRoboCop::TerminatorRoboCop(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), SteppingRobot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void TerminatorRoboCop::look(ostream &out, int x, int y)
{
    cout << robotName << " looks around its immediate neighbourhood." << endl;
    out << robotName << " looks around its immediate neighbourhood." << endl;
    movableStep.clear();
    movableLocation.clear();
    
    vector<int> newCoord;
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int d = 0; d < 8; d++) {

        int newRow = posY + dy[d];
        int newCol = posX + dx[d];

        // Check if the new position is within the battlefield
        if (newRow >= 0 && newRow < gameInfo->M && newCol >= 0 && newCol < gameInfo->N) {    
            newCoord.clear();
            // Check if there's a robot at the new position
            Robot* robot = battlefield->findRobotAtPosition(newRow, newCol);
            if (robot) {
                cout << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                out << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableStep.push_back(newCoord);
            }
            else {
                // cout << "Empty at (" << newRow << ", " << newCol << ")" << endl; // Commented out, it works but is messy
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableLocation.push_back(newCoord);
            }
        }
        else {
            // cout << "(" << newRow << ", " << newCol << ") is out of bounds" << endl; // Commented out, it works but is messy
        }
    }
}

void TerminatorRoboCop::move(ostream &out) 
{
    if (!(movableStep.empty()))
    {
        int otherRobotPosX, otherRobotPosY;
        int x = rand() % movableStep.size();
        otherRobotPosY = movableStep[x][0];
        otherRobotPosX = movableStep[x][1];

        Robot* robot = battlefield->findRobotAtPosition(otherRobotPosY, otherRobotPosX);
        robot->toggleAliveState();
        // robot->enterQueue();

        posY = movableStep[x][0];
        posX = movableStep[x][1];
        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
    else
    {
        int x = rand() % movableLocation.size();
        posY = movableLocation[x][0];
        posX = movableLocation[x][1];

        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
}

void TerminatorRoboCop::step(ostream &out)
{
    if (!(movableStep.empty()))
    {
        cout << robotName << " steps on a robot" << endl;
        out << robotName << " steps on a robot" << endl;
        kills++;
    }
    else
    {
        cout << robotName << " did not step on a robot" << endl;
        out << robotName << " did not step on a robot" << endl;
    }
}

void TerminatorRoboCop::fire(ostream &out)
{
}

void TerminatorRoboCop::fire(ostream &out, int x, int y) 
{
    if (posY + y < gameInfo->M && posX + x < gameInfo->N) {
        if (posY + y >= 0 && posX + x >= 0) {
            Robot* robot = battlefield->findRobotAtPosition(posY + y, posX + x);
            cout << robotName << " fires at (" << posY + y << ", " << posX + x << ")" << endl;
            out << robotName << " fires at (" << posY + y << ", " << posX + x << ")" << endl;
            if (robot)
            {
                cout << robotName << " hit a robot" << endl;
                robot->toggleAliveState();
                // robot->enterQueue();
                kills++;
            }
        }
        else {
            cout << robotName << " fires at an empty location." << endl;
            out << robotName << " fires at an empty location." << endl;
        }
    }
    else {
        cout << robotName << " fires at an empty location." << endl;
        out << robotName << " fires at an empty location." << endl;
    }
}

void TerminatorRoboCop::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// BLUE THUNDER
// ******************************************************************
BlueThunder::BlueThunder(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void BlueThunder::look(ostream &out, int x, int y)
{
    cout << robotName << " does not look around" << endl;
    out << robotName << " does not look around" << endl;
}

void BlueThunder::move(ostream &out) 
{
    cout << robotName << " does not move around" << endl;
    out << robotName << " does not move around" << endl;
}

void BlueThunder::step(ostream &out)
{
}

void BlueThunder::fire(ostream &out) 
{
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

    if (count == 8) {
        count = 0;
    }
    
    if (posY + dy[count] > 0 && posX + dx[count] > 0) {
        if (posY + dy[count] < gameInfo->M && posX + dx[count] < gameInfo->M) {
            Robot* robot = battlefield->findRobotAtPosition(posY + dy[count], posX + dx[count]);
            cout << robotName << " fires at the next clockwise direction at (" << posY + dy[count] << ", " << posX + dx[count] << ")" << endl;
            out << robotName << " fires at the next clockwise direction at (" << posY + dy[count] << ", " << posX + dx[count] << ")" << endl;
            if (robot)
            {
                cout << robotName << " hit a robot" << endl;
                out << robotName << " hit a robot" << endl;
                robot->toggleAliveState();
                // robot->enterQueue();
                kills++;
            }
        }
        else {
            cout << robotName << " fires at an empty location" << endl;
            out << robotName << " fires at an empty location" << endl;
        }
    }
    else {
        cout << robotName << " fires at an empty location" << endl;
        out << robotName << " fires at an empty location" << endl;
    }
    count++;
}

void BlueThunder::fire(ostream &out, int x, int y)
{
}

void BlueThunder::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}
// ******************************************************************
// MADBOT
// ******************************************************************
MadBot::MadBot(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void MadBot::look(ostream &out, int x, int y)
{
    cout << robotName << " does not look around" << endl;
    out << robotName << " does not look around" << endl;
}

void MadBot::move(ostream &out) 
{
    cout << robotName << " does not move around" << endl;
    out << robotName << " does not move around" << endl;
}

void MadBot::step(ostream &out)
{
}

void MadBot::fire(ostream &out) 
{
    int shootY = rand() % 3 - 1;
    int shootX = rand() % 3 - 1;
    while (abs(shootY) + abs(shootX) == 0) {
        shootY = rand() % 3 - 1;
        shootX = rand() % 3 - 1;
    }
    int firedAtY = posY + shootY;
    int firedAtX = posX + shootX;
    cout << robotName << " fires at (" << firedAtY << ", " << firedAtX << ")" << endl;
    out << robotName << " fires at (" << firedAtY << ", " << firedAtX << ")" << endl;
    Robot* robot = battlefield->findRobotAtPosition(firedAtY, firedAtX);
    if (robot)
    {   
        cout << robotName << " hit a robot" << endl;
        out << robotName << " hit a robot" << endl;
        robot->toggleAliveState();
        // robot->enterQueue();
        kills++;
    }
}

void MadBot::fire(ostream &out, int x, int y)
{
}

void MadBot::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// ROBOTANK
// ******************************************************************
RoboTank::RoboTank(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), SteppingRobot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void RoboTank::look(ostream &out, int x, int y)
{
    cout << robotName << " does not look around" << endl;
    out << robotName << " does not look around" << endl;
}

void RoboTank::move(ostream &out) 
{
    cout << robotName << " does not move around" << endl;
    out << robotName << " does not move around" << endl;
}

void RoboTank::step(ostream &out)
{
}

void RoboTank::fire(ostream &out) 
{
    for (int i = 0; i < 3; i++) {
        int shootY = rand() % gameInfo->M;
        int shootX = rand() % gameInfo->N;
        cout << robotName << " fires at (" << shootY << ", " << shootX << ")" << endl;
        out << robotName << " fires at (" << shootY << ", " << shootX << ")" << endl;
        Robot* robot = battlefield->findRobotAtPosition(shootY, shootX);
        if (robot)
        {
            cout << robotName << " hit a robot" << endl;
            out << robotName << " hit a robot" << endl;
            robot->toggleAliveState();
            // robot->enterQueue();
            kills++;
        }
    }
}

void RoboTank::fire(ostream &out, int x, int y)
{
}

void RoboTank::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// ULTIMATE ROBOT
// ******************************************************************
UltimateRobot::UltimateRobot(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), SteppingRobot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void UltimateRobot::look(ostream &out, int x, int y)
{
    cout << robotName << " looks around its immediate neighbourhood." << endl;
    out << robotName << " looks around its immediate neighbourhood." << endl;
    movableStep.clear();
    movableLocation.clear();
    
    vector<int> newCoord;
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int d = 0; d < 8; d++) {

        int newRow = posY + dy[d];
        int newCol = posX + dx[d];

        // Check if the new position is within the battlefield
        if (newRow >= 0 && newRow < gameInfo->M && newCol >= 0 && newCol < gameInfo->N) {    
            newCoord.clear();
            // Check if there's a robot at the new position
            Robot* robot = battlefield->findRobotAtPosition(newRow, newCol);
            if (robot) {
                cout << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                out << "Robot " << robot->getName() << " found at (" << newRow << ", " << newCol << ")" << endl;
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableStep.push_back(newCoord);
            }
            else {
                // cout << "Empty at (" << newRow << ", " << newCol << ")" << endl; // Commented out, it works but is messy
                newCoord.push_back(newRow);
                newCoord.push_back(newCol);
                movableLocation.push_back(newCoord);
            }
        }
        else {
            // cout << "(" << newRow << ", " << newCol << ") is out of bounds" << endl; // Commented out, it works but is messy
        }
    }
}

void UltimateRobot::move(ostream &out) 
{
    if (!(movableStep.empty()))
    {
        int otherRobotPosX, otherRobotPosY;
        int x = rand() % movableStep.size();
        otherRobotPosY = movableStep[x][0];
        otherRobotPosX = movableStep[x][1];

        Robot* robot = battlefield->findRobotAtPosition(otherRobotPosY, otherRobotPosX);
        robot->toggleAliveState();
        // robot->enterQueue();

        posY = movableStep[x][0];
        posX = movableStep[x][1];
        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
    else
    {
        int x = rand() % movableLocation.size();
        posY = movableLocation[x][0];
        posX = movableLocation[x][1];

        cout << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
        out << robotName << " moves to (" << posY << ", " << posX << ")" << endl;
    }
}

void UltimateRobot::step(ostream &out)
{
    if (!(movableStep.empty()))
    {
        cout << robotName << " steps on a robot" << endl;
        out << robotName << " steps on a robot" << endl;
        kills++;
    }
    else
    {
        cout << robotName << " did not step on a robot" << endl;
        out << robotName << " did not step on a robot" << endl;
    }
}

void UltimateRobot::fire(ostream &out) 
{
    for (int i = 0; i < 3; i++) {
        int shootY = rand() % gameInfo->M;
        int shootX = rand() % gameInfo->N;
        cout << robotName << " fires at (" << shootY << ", " << shootX << ")" << endl;
        out << robotName << " fires at (" << shootY << ", " << shootX << ")" << endl;
        Robot* robot = battlefield->findRobotAtPosition(shootY, shootX);
        if (robot)
        {
            cout << robotName << " hit a robot" << endl;
            out << robotName << " hit a robot" << endl;
            robot->toggleAliveState();
            // robot->enterQueue();
            kills++;
        }
    }
}

void UltimateRobot::fire(ostream &out, int x, int y)
{
}

void UltimateRobot::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}

// ******************************************************************
// COPYING ROBOT ATTRIBUTES
// ******************************************************************
void Robot::copyAttributesTo(Robot* other) const {
    other->robotName = this->robotName;
    other->posY = this->posY;
    other->posX = this->posX;
    other->lives = this->lives;
    other->kills = this->kills;
    other->alive = this->alive;
}
