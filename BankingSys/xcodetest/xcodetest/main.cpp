//
//  main.cpp
//  xcodetest
//
//  Created by Fatemeh Paknejad on 03.05.25.
//

#include <iostream>

class BankAccount{
private:
    double Balance;
    BankAccount(double Balance =0);
    void deposit(double amount){};
    void withdraw(double amount){};
    double checkBalance();
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
