#ifndef robot_h
#define robot_h

#include <string>
#include "gameinfo.hpp"
#include "battlefield.hpp"
using namespace std;

class GameInfo;
class Battlefield;

class Robot {
protected:
    string robotType;
    string robotName;
    int posY;
    int posX;
    int lives = 3;
    char symbol = 'X';
    int kills = 0;
    bool alive = true;
    GameInfo* gameInfo = nullptr;
    Battlefield* battlefield = nullptr;
    vector<vector<int>> movableLocation;
    vector<vector<int>> movableStep;

public:
    string getName() const {return robotName;}
    Robot(const string& type, const string& name, int r, int c);
    
    void parseRobotInfo(const string& line);
    virtual char getSymbol() const { return 'M'; }
    bool isAlive() { return alive; }
    void toggleAliveState() { alive = !alive; }
    int getLives() { return lives; }
    void reduceLives() { lives--; }
    void setPosY(int y) { posY = y; }
    void setPosX(int x) { posX = x; }
    int getKills() { return kills; }
    void setKills(int kills) { this->kills = kills; }
    string getType() { return robotType; }

    void setGrid(Battlefield& battlefield) { this->battlefield = &battlefield; } 
    void setGameInfo(GameInfo& gameInfo) { this->gameInfo = &gameInfo; }

    // These are the virtual functions using polymorphism so that each function can have different definitions.
    virtual void look(ostream &out, int x, int y) = 0;
    virtual void move(ostream &out) = 0;
    virtual void step(ostream &out) = 0;
    virtual void fire(ostream &out, int x, int y) = 0;
    virtual void fire(ostream &out) = 0;
    virtual void printInfo() const = 0;
    virtual ~Robot() = default;
    void copyAttributesTo(Robot* other) const;

    // Accessor methods
    int getPosY() const { return posY; }  // Getter for posY
    int getPosX() const { return posX; }  // Getter for posX
    string getRobotName() const { return robotName; }
};

// movingRobot class inheriting robot base class
class MovingRobot : public virtual Robot{
    public:
        MovingRobot(const string& type, const string& name, int r, int c);
        // TODO: Moving logic;
        void move(ostream &out);
};

// ShootingRobot class inheriting robot base class
class ShootingRobot : public virtual Robot{
    public:
        ShootingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void fire(ostream &out, int x, int y);
        void fire(ostream &out);
};

class SeeingRobot : public virtual Robot{
    public:
        SeeingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void look(ostream &out, int x, int y);
};

class SteppingRobot : public virtual Robot{
    public:
        SteppingRobot(const string& type, const string& name, int r, int c);
        // TODO: Shooting logic;
        void step(ostream &out);
};

class RoboCop : public MovingRobot, public SeeingRobot, public ShootingRobot{
    public:
        RoboCop(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'R'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
};

class Terminator : public MovingRobot, public SeeingRobot, public SteppingRobot{
    public:
        Terminator(const string& type, const string& name, int r, int c);
        
        char getSymbol() const override { return 'T'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void fire(ostream &out) override;
        void printInfo() const override;
        void robotUpgrade();
};

class TerminatorRoboCop : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    public:
        TerminatorRoboCop(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return '&'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
        ~TerminatorRoboCop() override = default;
};

class BlueThunder : public ShootingRobot{
    int count = 0;
    public:
        BlueThunder(const string& type, const string& name, int r, int c);
        
        char getSymbol() const override { return 'B'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
        ~BlueThunder() override = default;
};

class MadBot : public ShootingRobot{
    public:
        MadBot(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'M'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
        ~MadBot() override = default;
        // TODO: Once value return, we can pass it into the action classes to perform
};

class RoboTank : public MovingRobot, public SeeingRobot, public SteppingRobot, public ShootingRobot{
    public:
        RoboTank(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 't'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
        ~RoboTank() override = default;
};

class UltimateRobot : public MovingRobot, public SteppingRobot, public SeeingRobot, public ShootingRobot{
    public:
        UltimateRobot(const string& type, const string& name, int r, int c);

        char getSymbol() const override { return 'U'; }

        void look(ostream &out, int x, int y) override;
        void move(ostream &out) override;
        void step(ostream &out) override;
        void fire(ostream &out) override;
        void fire(ostream &out, int x, int y) override;
        void printInfo() const override;
        ~UltimateRobot() override = default;
};

class CustomRobot{
    //TODO: All the functions;
};

#endif // robot_h
