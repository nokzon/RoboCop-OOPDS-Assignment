#ifndef robot_h
#define robot_h

#include <string>
#include <iostream>
using namespace std;

class robot {
protected:
    string robotType;
    string robotName;
    int posY;
    int posX;
    char symbol = 'x';
    int lives = 0;

public:
    robot(const string& type, const string& name, int r, int c) 
        : robotType(type), robotName(name), posY(r), posX(c) {}

    // These are the virtual functions using polymorphism so that each function can have different definitions.
    virtual void look(int x, int y) = 0;
    virtual void move() = 0;
    virtual void fire(int x, int y) = 0;
    virtual void printInfo() const = 0;

    // Additional common robot functionalities can be added here
};

// movingRobot class inheriting robot base class
class movingRobot : public robot{
protected:
    string type, name;
    int r, c;
public:
    movingRobot(const string& type, const string& name, int r, int c) : robot(type, name, r, c) {}
    // TODO: Moving logic;
};

// shootingRobot class inheriting robot base class
class shootingRobot : public robot{
protected:
    string type, name;
    int r, c;
public:
    shootingRobot(const string& type, const string& name, int r, int c) : robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

class seeingRobot : public robot{
protected:
    string type, name;
    int r, c;
public:
    seeingRobot(const string& type, const string& name, int r, int c) : robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

class steppingRobot : public robot{
protected:
    string type, name;
    int r, c;
public:
    steppingRobot(const string& type, const string& name, int r, int c) : robot(type, name, r, c) {}
    // TODO: Shooting logic;
};

// madBot derived class inheriting shootingRobot derived class
class madBot : public shootingRobot{
public:
    madBot(const string& type, const string& name, int r, int c) : shootingRobot(type, name, r, c) {}

    void look(int x, int y) override {
        cout << robotName << " is madly looking at (" << x << ", " << y << ")" << endl;
    }

    void move() override {
        cout << robotName << " is madly moving" << endl;
    }

    void fire(int x, int y) override {
        cout << robotName << " is madly firing at (" << x << ", " << y << ")" << endl;
    }

    void printInfo() const override {
        cout << "Type: " << robotType << ", Name: " << robotName << ", Position: ("
             << posY << ", " << posX << ")" << endl;
    }
    // TODO: Once value return, we can pass it into the action classes to perform
    
};

class roboTank : public movingRobot, public seeingRobot, public steppingRobot, public shootingRobot{
    // TODO: All the functions;
};


class RoboCop : public movingRobot, public seeingRobot, public shootingRobot{
    //TODO: All the functions;
};

class Terminator : public movingRobot, public seeingRobot, public steppingRobot{
    //TODO: All the functions;
};

class TerminatorRoboCop : public movingRobot, public seeingRobot, public steppingRobot, public shootingRobot{
    //TODO: All the functions;
};

class BlueThunder : public shootingRobot{
    //TODO: All the functions;
};

class madbot : public shootingRobot{
    //TODO: All the functions;
};

class RoboTank : public movingRobot, public seeingRobot, public steppingRobot, public shootingRobot{
    //TODO: All the functions;
};

class UltimateRobot : public movingRobot, public steppingRobot, public seeingRobot, public shootingRobot{
    //TODO: All the functions;
};

class CustomRobot{
    //TODO: All the functions;
};

#endif // robot_h
