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
#include "TaskRepository.hpp"

class TaskManager{
    
private:
    std::vector<Task> taskList;
    ITaskRepository *repo;
    
public:
    int runMenu();
    void addTask();
    void listTasks() const;
    void markTaskDone();
    void deleteTask();
    void filterTasks() const;
    void editTaskTitle();
    

};

#endif /* TaskManager_hpp */
