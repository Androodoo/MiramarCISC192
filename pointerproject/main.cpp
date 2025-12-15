#include <iostream>
#include "Task.h"
#include <memory>

// PART C (unique pointers)
class PartC {
private:
    std::unique_ptr<Task[]> tasks;
    int size; //current amt of tasks
    int capacity; //max tasks

public:
    //making our object using the given size and capacity
    PartC(int initialCapacity) {
        this->tasks = std::make_unique<Task[]>(initialCapacity);
        this->size = 0;
        this->capacity = initialCapacity;
    }

    void addTask(const std::string& desc) {
        //in case we try going over the limit
        if (size >= capacity) {
            return;
        }
        //add a task and increasing the current amt of tasks
        tasks[size] = Task(size + 1, desc);
        size++;
    }

    void removeTask(int id) {
        //setting it default to -1 so it doesn't already apply to any tasks before removing
        int indexToRemove = -1;
        //removing iteration of i, same as id of task.
        for (int i = 0; i < size; i++) {
            if (tasks[i].getId() == id) {
                indexToRemove = i;
                break;
            }
        }
        //if nothing matches, nothing happens
        if (indexToRemove == -1) {
            return;
        }
        //downsizing and shifting after removing a task
        for (int j = indexToRemove; j < size - 1; j++) {
            tasks[j] = tasks[j + 1];
        }
        size--;
    }

    //code should be self explanatory here
    void listTasks() const {
        std::cout << "CURRENT TASKS:\n";
        for (int i = 0; i < size; i++) {
            std::cout << tasks[i].getDescription() << ")\n";
        }
        std::cout << "\n";
    }
};

// PART B Helper Functions
void addTask(Task* tasks, int& size, int capacity, const std::string& desc) {
    //locates the next open slot
    if (size < capacity) {
        Task* taskp = tasks + size;
        *taskp = Task(size + 1, desc);
        size++;
        return;
    }
    return;
}

void removeTask(Task* tasks, int& size, int id) {
    Task* currentTask = tasks;
    //setting to -1 incase nothing matches
    int taskToRemove = -1;
    //go through the list, find the one that matches, and then remove
    for (int i =0; i< size; i++) {
        if ((currentTask + i)->getId() == id ) {
            taskToRemove = i;
            break;
        }
    }
    //do nothing if nothing matches
    if (taskToRemove == -1) {
        return;
    }
    //remove and shift
    for (int j = taskToRemove; j < size - 1; j++) {
        *(tasks + j) = *(tasks + j + 1);
    }

    size--;
}

//self explanatory, go through the list and cout it
void listTasks(Task* tasks, int size) {
    std::cout << "CURRENT TASKS:\n";
    for (int i = 0; i < size; i++) {
        Task* t = tasks + i;
        std::cout << t->getDescription() << "\n";
    }
    std::cout << "\n";
};

//PART A Helper function
//marking it completed
void completeTask(Task* t) {
    t->markCompleted();
}

int main(){
    // PART AAAAAAAAA
    std::cout<<"PART A\n";
    
    Task t1(1, "Finish CPP project"); //task creation
    Task t2(2, "Study for exam");

    Task* p1 = &t1; //assigning pointers & tasks
    Task* p2 = &t2;

    //tasks are currently uncompleted    
    std::cout << "p1: " << p1->isCompleted() << "\n"; //0 means uncompleted, 1 means completed
    std::cout << "p2: " << p2->isCompleted() << "\n";
    completeTask(p1); //check as complete
    completeTask(p2);
    std::cout << "Completed;\n";
    //tasks are now completed
    std::cout << "p1: " << p1->isCompleted() << "\n"; //0 means uncompleted, 1 means completed
    std::cout << "p2: " << p2->isCompleted() << "\n";
    std::cout<<"\n\n\n";




    // PART BBBBBBBBBBBB
    std::cout<<"PART B\n";
    
    int capacity = 5;
    int size = 0;

    Task* tasks = new Task[capacity];
    // add 3 tasks
    addTask(tasks, size, capacity, "1FighterPilot"); //these are the jobs i've always wanted to do btw lol
    addTask(tasks, size, capacity, "2AerospaceEngineer");
    addTask(tasks, size, capacity, "3Astronaut");

    // should have 3 tasks listed
    listTasks(tasks, size);
    // task removed
    removeTask(tasks, size, 2);

    // should only have 2 tasks
    listTasks(tasks, size);

    delete[] tasks;
    std::cout<<"\n\n\n";




    // PART CCCCCCCCCC
    std::cout<<"PART C\n";

    PartC taskManager(capacity);
    taskManager.addTask("1Running"); //these are my hobbies
    taskManager.addTask("2Iceskating");
    taskManager.addTask("3Swimming");

    taskManager.listTasks();
    taskManager.removeTask(2);
    taskManager.listTasks();

    // delete not needed, its a smart ptr
    std::cout<<"\n\n\n";
    return 0;
}