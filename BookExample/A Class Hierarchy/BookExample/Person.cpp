//
//  Person.cpp
//  
//
//  Created by Fatemeh Paknejad on 30.06.25.
//

#include "Person.hpp"
#include <String>
#include <iostream>

Person::Person(string name):
               m_name(name){
                   
               }

void Person::print(){
    std::cout<<"Person "<< m_name <<std::endl;
}


