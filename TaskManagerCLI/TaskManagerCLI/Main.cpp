//
//  Main.cpp
//  TaskManagerCLI
//
//  Created by Fatemeh Paknejad on 03.07.25.
//

#include <stdio.h>

class Task{
private:
    std::string title;
    bool isDone;
    
public:
    Task(std::string title, bool isDone);
    
    void markDone(std::strin title, bool isDone);
    void printTask();
};

int main(){
    
    Task taskObj;
}
