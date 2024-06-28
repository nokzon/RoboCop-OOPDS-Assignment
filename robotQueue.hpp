#ifndef ROBOTQUEUE_HPP
#define ROBOTQUEUE_HPP

#include <vector>
#include "robots.hpp" // Include the header for the Robot class

class RobotQueue {
private:
    std::vector<Robot*> queue;

public:
    void enqueue(Robot* robot);
    Robot* dequeue();
    bool isEmpty() const;
    size_t size() const;
};

#endif // ROBOTQUEUE_HPP
