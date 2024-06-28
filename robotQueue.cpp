#include <iostream>
#include "robotQueue.hpp"

void RobotQueue::enqueue(Robot* robot) {
    queue.push_back(robot);
    for (const auto& element : queue){
        cout << element << " ";
    }
}

Robot* RobotQueue::dequeue() {
    if (queue.empty()) {
        throw std::underflow_error("Queue is empty");
    }
    Robot* robot = queue.front();
    queue.erase(queue.begin());
    return robot;
}

bool RobotQueue::isEmpty() const {
    return queue.empty();
}

size_t RobotQueue::size() const {
    return queue.size();
}
