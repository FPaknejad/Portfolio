//
//  Task.cpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 03.07.25.
//

#include "Task.h"
#include <iostream>
void Task::markDone() {
    done = true;
}

void Task::printTask() const {
    std::cout << (done ? "[X] " : "[ ] ") << title << std::endl;
}

bool Task::isDone() const {
    return done;
}

Task::Task(std::string title, bool isDone)
    : title(title), done(isDone) {}

std::string Task::getTitle() const{
    return title;
}

void Task::setTitle(const std::string &newTitle){
    
    title = newTitle;
    
}


