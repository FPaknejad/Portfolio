//
//  Person.hpp
//  
//
//  Created by Fatemeh Paknejad on 30.06.25.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
class Person{
public:
    Person(string name);
    virtual void print();
    
private:
    string m_name;
};
#endif /* Person_hpp */
