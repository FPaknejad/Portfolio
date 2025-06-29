//
//  Student.cpp
//  A Class Hierarchy
//
//  Created by Fatemeh Paknejad on 11.06.25.
//

#include "Student.hpp"
#include "Person.hpp"
#include <String>
#include <iostream>

using namespace std;

Student::Student (string name, string university):Person(name),m_university(university){}

