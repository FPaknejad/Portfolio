//
//  Employee.hpp
//  
//
//  Created by Fatemeh Paknejad on 01.07.25.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>

class Employee : public Person {
public:
    Employee(string name, string company);
    void print();
    
private:
    string m_company;
}

#endif /* Employee_hpp */
