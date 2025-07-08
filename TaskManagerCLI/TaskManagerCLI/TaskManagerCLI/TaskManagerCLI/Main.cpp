//
//  Main.cpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 03.07.25.
//

#include <stdio.h>
#include <iostream>
#include "Task.h"
#include <vector>
#include "TaskManager.hpp"

int main(){
    //Task taskObj("task 1",false);
//  std::vector<Task> taskList;
    
    TaskManager manageObj;
    
    manageObj.runMenu();
        return 0;
}


