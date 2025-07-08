//
//  TaskManager.cpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 05.07.25.
//

#include "TaskManager.hpp"
#include "Task.h"

void TaskManager::addTask(){
    std::string taskTitle;
    std::cout<< "Enter the Task title" <<std::endl;
    std::cin.ignore();
    std::getline(std::cin,taskTitle);
    taskList.push_back(Task(taskTitle,false));
}

void TaskManager::listTasks(){
    for(Task &t : taskList){
        t.printTask();
    }
}

void TaskManager::markTaskDone(){
    for (int i = 0; i < taskList.size(); ++i) {
        std::cout << i + 1 << ". ";
        taskList[i].printTask();
    }
    int taskIndex;
    std::cout<<"Enter task Index"<<std::endl;
    std::cin>>taskIndex;
    if (std::cin.fail()) {
        std::cin.clear(); // clear error state
        std::cin.ignore(1000, '\n'); // discard bad input
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }
    if (taskIndex < 1 || taskIndex > taskList.size()) {
        std::cout << "invalid Index" << std::endl;
        return;
    }
    taskList[taskIndex-1].markDone();

}

void TaskManager::deleteTask(){
    std::cout<<"Enter the index of tasks from the following list to delete"<<std::endl;
    for (int i = 0; i < taskList.size(); ++i) {
        std::cout << i + 1 << ". ";
        taskList[i].printTask();
    }
    int taskIndex;
    std::cin >> taskIndex;
    if (std::cin.fail()) {
        std::cin.clear(); // clear error state
        std::cin.ignore(1000, '\n'); // discard bad input
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }
    if (taskIndex < 1 || taskIndex > taskList.size()) {
        std::cout << "Please enter a valid index number" << std::endl;
        return;
    }
    taskList.erase(taskList.begin() + taskIndex - 1);
}
void TaskManager::filterTask(){
    std::cout<<"Enter the filter option:\n1. Show all\n2. Show completed\n3. Show incomplete\n"<<std::endl;
    
    int filterOption;
    
    while(true){
        std::cin>>filterOption;
        if (std::cin.fail()) {
            std::cin.clear(); // clear error state
            std::cin.ignore(1000, '\n'); // discard bad input
            std::cout << "Invalid input. Please enter a number.\n";
            return;
        }
        
        switch (filterOption) {
            case 1:
                TaskManager::listTasks();
                break;
                
            case 2:
                for(Task &t:taskList){
                    if( t.isDone()){
                        t.printTask();
                    }
                        
                    }
                break;
            case 3:
                for(Task &t : taskList){
                    if(t.isDone() == false){
                        t.printTask();
                    }
                    }
                break;
                
            default:
                break;
        }
    }
}
int TaskManager:: runMenu(){
    int menuIndex;
    
    while (true){
        std::cout<<"Enter the Number of options \n"<<"1. Add Task \n2. List Tasks\n3. Mark Task as Done\n4. delete task\n5. Exit\n6. Filter tasks"<<std::endl;
        
        std::cin>>menuIndex;
        if (menuIndex < 1 || menuIndex > 6){
            std::cout<<"Invalid index. Please enter a valid number between 1 to 6"<<std::endl;
        }
        if (std::cin.fail()) {
            std::cin.clear(); // clear error state
            std::cin.ignore(1000, '\n'); // discard bad input
            std::cout << "Invalid input. Please enter a number.\n";
        }
        else{
            switch (menuIndex) {
                case 1:
                    addTask();
                    break;
                case 2:
                    listTasks();
                    break;
                case 3:
                    markTaskDone();
                    break;
                case 4:
                    deleteTask();
                    break;
                case 5:
                    return 0;
                case 6:
                    filterTask();
                    break;
                default:
                    break;
            }
        
    }

}
    }
