#include "robots.hpp"
#include <iostream>
#include <string>
#include <cmath>
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

void MovingRobot::move()
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

void ShootingRobot::fire(int x, int y)
{
    // int shootX = rand() % 21 - 10; // generate X between -10 to 10
    // int shootY = rand() % 21 - 10;

    // while (abs(shootX) + abs(shootY) > 10 || abs(shootX) + abs(shootY) == 0)
    // {
    //     int shootX = rand() % 21 - 10;
    //     int shootY = rand() % 21 - 10;
    // }
    // This function targets an element in the battlefield and destroys it if it's not '.'
    // Randomly generates x and y between -10 to 10, if |x| + |y| > 10, or |x| + |y| == 0, generate again
    // Shoots at the x and y coordinate generated relative to the robot's position
}

void ShootingRobot::fire()
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

void SeeingRobot::look(int x, int y)
{
    // Looks at a specific coordinate on the grid, then reveals a 3x3 area around that coordinate
    // 3x3 area needs to reveal whether parts of it are in battlefield or not, and reveal robot if there's one
}

// ******************************************************************
// STEPPING ROBOT
// ******************************************************************
SteppingRobot::SteppingRobot(const string& type, const string& name, int r, int c) 
    : Robot(type, name, r, c) {}

void SteppingRobot::step()
{
    // If a non-stepping robot moves to a location that has another robot, it'll choose another coordinate to move to (rng)
    // Can check if the moving robot is a stepping robot, then ALLOW it to kill the enemy robot and occupy its space by calling this function
}

// ******************************************************************
// ROBOCOP
// ******************************************************************
RoboCop::RoboCop(const string& type, const string& name, int r, int c)
    : Robot(type, name, r, c), MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), ShootingRobot(type, name, r, c) {}

void RoboCop::look(int x, int y)
{
    cout << robotName << " looks at (" << y << ", " << x << ")" << endl;
}

void RoboCop::move() 
{
    cout << robotName << " moves to x, y" << endl;
}

void RoboCop::step()
{
    cout << robotName << " steps on a robot" << endl;
}

void RoboCop::fire(int x, int y) 
{
    cout << robotName << " does not fire" << endl;
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

void Terminator::look(int x, int y)
{
    cout << robotName << " looks at its immediate neighbourhood" << endl;
}

void Terminator::move() 
{
    cout << robotName << " moves to x, y" << endl;
}

void Terminator::step()
{
    cout << robotName << " steps on a robot" << endl;
}

void Terminator::fire(int x, int y) 
{
    cout << robotName << " does not fire" << endl;
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

void TerminatorRoboCop::look(int x, int y)
{
    cout << robotName << " looks at (" << y << ", " << x << ")" << endl;
}

void TerminatorRoboCop::move() 
{
    cout << robotName << " moves to x, y" << endl;
}

void TerminatorRoboCop::step()
{
    cout << robotName << " steps on a robot" << endl;
}

void TerminatorRoboCop::fire(int x, int y) 
{
    cout << robotName << " fires at (" << y << ", " << x << ")" << endl;
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

void BlueThunder::look(int x, int y)
{
    cout << robotName << " does not look around" << endl;
}

void BlueThunder::move() 
{
    cout << robotName << " does not move around" << endl;
}

void BlueThunder::step()
{
    cout << robotName << " does not step" << endl;
}

void BlueThunder::fire(int x, int y) 
{
    cout << robotName << " fires at the next clockwise direction at (" << y << ", " << x << ")" << endl;
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

void MadBot::look(int x, int y)
{
    cout << robotName << " does not look around" << endl;
}

void MadBot::move() 
{
    cout << robotName << " does not move around" << endl;
}

void MadBot::step()
{
    cout << robotName << " does not step" << endl;
}

void MadBot::fire(int x, int y) 
{
    cout << robotName << " fires at (" << y << ", " << x << ")" << endl;
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

void RoboTank::look(int x, int y)
{
    cout << robotName << " does not look around" << endl;
}

void RoboTank::move() 
{
    cout << robotName << " does not move around" << endl;
}

void RoboTank::step()
{
    cout << robotName << " does not step" << endl;
}

void RoboTank::fire(int x, int y) 
{
    cout << robotName << " fires at (" << y << ", " << x << ")" << endl;
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

void UltimateRobot::look(int x, int y)
{
    cout << robotName << " looks at (" << y << ", " << x << ")" << endl;
}

void UltimateRobot::move() 
{
    cout << robotName << " moves to x, y" << endl;
}

void UltimateRobot::step()
{
    cout << robotName << " steps on a robot" << endl;
}

void UltimateRobot::fire(int x, int y) 
{
    cout << robotName << " fires at (" << y << ", " << x << ")" << endl;
}

void UltimateRobot::printInfo() const 
{
    cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
         << posY << ", " << posX << ")" << endl;
}