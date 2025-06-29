//
//  Person.hpp
//  A Class Hierarchy
//
//  Created by Fatemeh Paknejad on 11.06.25.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
class Person{
public:
    Person(string name);
    virtual void print();
    
private:
    string name;
    
}


#endif /* Person_hpp */
