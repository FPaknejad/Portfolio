//
//  Student.hpp
//  A Class Hierarchy
//
//  Created by Fatemeh Paknejad on 11.06.25.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>

class Studen : public Person {
public:
    Student(string name, string University);
    void print();
    
private:
    string m_university;
};

#endif /* Student_hpp */
