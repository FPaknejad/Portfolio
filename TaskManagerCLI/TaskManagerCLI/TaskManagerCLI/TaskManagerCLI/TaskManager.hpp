//
//  TaskManager.hpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 05.07.25.
//

#ifndef TaskManager_hpp
#define TaskManager_hpp

#include <stdio.h>
#include <fstream>
#include "Task.h"

class TaskManager{
    
private:
    std::vector<Task> taskList;
    
public:
    void addTask();
    void listTasks();
    void markTaskDone();
    void deleteTask();
    int runMenu();
    void filterTask();
    void saveToFile();
    void readFile();
};

#endif /* TaskManager_hpp */
