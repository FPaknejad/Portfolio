//
//  Student.hpp
//  
//
//  Created by Fatemeh Paknejad on 01.07.25.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>

class Student : public Person {
public:
    Student (string name, string university);
    void print();
    
private:
    string m_university;
};

#endif /* Student_hpp */
