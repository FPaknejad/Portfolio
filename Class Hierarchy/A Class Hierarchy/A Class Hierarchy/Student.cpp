//
//  Student.cpp
//  
//
//  Created by Fatemeh Paknejad on 01.07.25.
//

#include "Student.hpp"
#include "Person.hpp"
#include <String>
#include <iostream>

Student::Student(string name, string university)
: person (name), m_university(university){}


void Student::print(){
    Person::print();
    std::cout<< "University "<< m_university  << std::endl;
}


