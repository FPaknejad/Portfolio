//
//  Person.cpp
//  A Class Hierarchy
//
//  Created by Fatemeh Paknejad on 11.06.25.
//

#include "Person.hpp"

#include <String>
#include <iostream>

using namespace std;

Person::Person(string name)
:m_name(name){}

void Person::print(){
    cout<<"Person "<<m_name<<endl;
}

