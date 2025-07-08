//
//  Employee.cpp
//  
//
//  Created by Fatemeh Paknejad on 01.07.25.
//

#include "Employee.hpp"
#include "Person.hpp"

#include <string>
#include <iostream>

Employee::Employee(string name, string company)
:Person(name), m_company(company) {
    
}

void Employee::print(){
    Person::print();
    cout << "Company "<<m_company <<std::endl;
}
