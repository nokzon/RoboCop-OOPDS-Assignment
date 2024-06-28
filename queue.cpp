#include "robotQueue.hpp"

void enqueue(Robot* robot) {
    queue.push_back(robot);
}

Robot* dequeue() {
    if (queue.empty()) {
        throw std::underflow_error("Queue is empty");
    }
    Robot* robot = queue.front();
    queue.erase(queue.begin());
    return robot;
}

bool isEmpty() const {
    return queue.empty();
}

size_t size() const {
    return queue.size();
}
