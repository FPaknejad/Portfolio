//
//  Task.cpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 03.07.25.
//

#include "Task.h"
#include <iostream>

Task::Task(const std::string& title, bool done)
    : title(title), done(done) {}

void Task::markDone() {
    done = true;
}

void Task::setTitle(const std::string& newTitle) {
    title = newTitle;
}

bool Task::isDone() const {
    return done;
}

void Task::printTask() const {
    std::cout << (done ? "[x] " : "[ ] ") << title << std::endl;
}


std::string Task::getTitle() const {
    return title;  // or whatever your internal variable is
}