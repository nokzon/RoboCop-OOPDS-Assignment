#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
using namespace std;

class Robot {
protected:
    string robotType;
    string robotName;
    int row;
    int column;

public:
    Robot(const string& type, const string& name, int r, int c)
        : robotType(type), robotName(name), row(r), column(c) {}

    virtual ~Robot() {}

    virtual void printInfo() const {
        cout << "Type: " << robotType << ", Name: " << robotName
             << ", Position: (" << row << ", " << column << ")" << endl;
    }

    // Additional common robot functionalities can be added here
};

class madBot : public Robot {
public:
    madBot(const string& name, int r, int c) : Robot("Madbot", name, r, c) {}
    
    // Additional specific functionalities can be added here
};

class roboTank : public Robot {
public:
    roboTank(const string& name, int r, int c) : Robot("RoboTank", name, r, c) {}
    
    // Additional specific functionalities can be added here
};

// Similarly, define other robot types

#endif // ROBOT_H
