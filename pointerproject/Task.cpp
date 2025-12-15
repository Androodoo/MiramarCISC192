#include <string>
#include "Task.h"
//basically just setters and getters, code is self explanatory

Task::Task() {
    this->id = 0;
    this->description = "";
    this->completed = false;
}

Task::Task(int id, const std::string& desc) {
    this->id = id;
    this->description = desc;
    this->completed = false;
};

void Task::markCompleted() {
    completed = true;
};
bool Task::isCompleted() const {
    return completed;
}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const{
    return description;
}