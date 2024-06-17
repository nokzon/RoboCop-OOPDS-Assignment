#ifndef robot_h
#define robot_h

#include <string>
#include <iostream>
#include "gameInfo.h"
using namespace std;

class Robot {
protected:
    string robotType;
    string robotName;
    int posY;
    int posX;
    char symbol = 'x';
    int lives = 0;

public:
    Robot(const string& type, const string& name, int r, int c) 
        : robotType(type), robotName(name), posY(r), posX(c) {}
    
    // Pure virtual function to get the symbol representing each robot
    virtual char getSymbol() const = 0;

    // These are the virtual functions using polymorphism so that each function can have different definitions.
    virtual void look(int x, int y) = 0;
    virtual void move() = 0;
    virtual void fire(int x, int y) = 0;
    void printInfo() {
        cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
             << posY << ", " << posX << ")" << endl;
    }

    // Additional common robot functionalities can be added here
    
};

// MovingRobot class inheriting robot base class
class MovingRobot : public Robot{
protected:
    string type, name, r, c;
public:
    MovingRobot(const string& type, const string& name, int r, int c) : Robot(type, name, r, c) {}
    // TODO: Moving logic;
};

// ShootingRobot class inheriting robot base class
class ShootingRobot : public Robot{
protected:
    string type, name, r, c;
public:
    ShootingRobot(const string& type, const string& name, int r, int c) : Robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

class SeeingRobot : public Robot{
protected:
    string type, name, r, c;
public:
    SeeingRobot(const string& type, const string& name, int r, int c) : Robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

class SteppingRobot : public Robot{
protected:
    string type, name, r, c;

public:
    SteppingRobot(const string& type, const string& name, int r, int c) : Robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

// Madbot derived class inheriting shootingRobot derived class
class Madbot : public ShootingRobot{
public:
    Madbot(const string& type, const string& name, int r, int c) : ShootingRobot(type, name, r, c) {}

    char getSymbol() const override {return 'M';}

    void look(int x, int y) override {
        cout << robotName << " does not look around" << endl;
    }

    void move() override {
        cout << robotName << " does not move" << endl;
    }

    void fire(int x, int y) override {
        cout << robotName << " is madly firing at (" << y << ", " << x << ")" << endl;
    }
    // TODO: Once value return, we can pass it into the action classes to perform
};

class RoboTank : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
public:
    RoboTank(const string& type, const string& name, int r, int c) : MovingRobot(type, name, r, c), SeeingRobot(type, name, r, c), SteppingRobot(type, name, r, c), ShootingRobot(type, name, r ,c) {}

    char getSymbol() const override {return 'R';}

    void look(int x, int y) override {
        cout << MovingRobot::robotName << " looks at (" << y << ", " << x << ")" << endl;
    }

    void move() override {
        cout << MovingRobot::robotName << " moves towards " << endl;
    }

    void fire(int x, int y) override {
        cout << MovingRobot::robotName << " is madly firing at (" << y << ", " << x << ")" << endl;
    }
    // TODO: Once value return, we can pass it into the action classes to perform
};

class RoboCop : public MovingRobot, public SeeingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class Terminator : public MovingRobot, public SeeingRobot, public SteppingRobot{
    //TODO: All the functions;
};

class TerminatorRoboCop : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class BlueThunder : public ShootingRobot{
    //TODO: All the functions;
};

class UltimateRobot : public MovingRobot, public SteppingRobot, public SeeingRobot, public ShootingRobot{
    //TODO: All the functions;
};

class CustomRobot{
    //TODO: All the functions;
};

#endif // robot_h
