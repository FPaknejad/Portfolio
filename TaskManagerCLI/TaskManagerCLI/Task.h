//
//  Task.h
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 03.07.25.
//

#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string title;
    bool done;
    
public:
    Task(std::string desc, bool isDone);

    void markDone();
    void printTask() const;
    bool isDone() const;
    std::string getTitle() const;
    void setTitle(const std::string& newTitle);
};

#endif // TASK_H
