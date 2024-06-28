#ifndef robot_h
#define robot_h

#include <string>
#include "gameinfo.hpp"
using namespace std;

class Robot {
protected:
    string robotType;
    string robotName;
    int posY;
    int posX;
    int lives = 0;
    char symbol = 'X';

public:
    Robot(const string& type, const string& name, int r, int c);
    
    void parseRobotInfo(const string& line);
    virtual char getSymbol() const { return 'M'; }

    int getPosY() const { return posY; }  // Getter for posY
    int getPosX() const { return posX; }  // Getter for posX

    // These are the virtual functions using polymorphism so that each function can have different definitions.
    virtual void look(int x, int y) = 0;
    virtual void move() = 0;
    virtual void step() = 0;
    virtual void fire(int x, int y) = 0;
    virtual void printInfo() const = 0;
};

// movingRobot class inheriting robot base class
class MovingRobot : public virtual Robot{
    public:
        MovingRobot(const string& type, const string& name, int r, int c);
        // TODO: Moving logic;
        void move();
};

// ShootingRobot class inheriting robot base class
class ShootingRobot : public virtual Robot{
    public:
        ShootingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void fire(int x, int y);
        void fire();
};

class SeeingRobot : public virtual Robot{
    public:
        SeeingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void look(int x, int y);
};

class SteppingRobot : public virtual Robot{
    public:
        SteppingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void step();
};

class RoboCop : public MovingRobot, public SeeingRobot, public ShootingRobot{
    public:
        RoboCop(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'R'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class Terminator : public MovingRobot, public SeeingRobot, public SteppingRobot{
    public:
        Terminator(const string& type, const string& name, int r, int c);
        
        char getSymbol() const override { return 'T'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class TerminatorRoboCop : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    public:
        TerminatorRoboCop(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return '&'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class BlueThunder : public ShootingRobot{
    public:
        BlueThunder(const string& type, const string& name, int r, int c);
        
        char getSymbol() const override { return 'B'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class MadBot : public ShootingRobot{
    public:
        MadBot(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'M'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
        // TODO: Once value return, we can pass it into the action classes to perform
};

class RoboTank : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    public:
        RoboTank(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 't'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class UltimateRobot : public MovingRobot, public SteppingRobot, public SeeingRobot, public ShootingRobot{
    public:
        UltimateRobot(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'U'; }

        void look(int x, int y) override;
        void move() override;
        void step() override;
        void fire(int x, int y) override;
        void printInfo() const override;
};

class CustomRobot{
    //TODO: All the functions;
};

#endif // robot_h
