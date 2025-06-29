//  BankingSysPractice.cpp
//
//  Created by Fatemeh Paknejad


#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype> // needed for isalpha

class BankAccount{
private:
    double Balance;
    std::string ownerName;
    
public:
    BankAccount(std::string Name = "", double Balance = 0)
    : ownerName(Name), Balance(Balance) {}
    
    void deposit(double amount){
        Balance += amount;
    };
    void withdraw(double amount){
        Balance -= amount;
    };
    double checkBalance(){
        return Balance;
    };
    
    std::string getOwnerName() const{
        return ownerName;
    };
};

class Banksystem{
    std::vector<BankAccount> Account;
public:
    
    void newAccount(std::string Name, double Balance){
        BankAccount newAcc(Name, Balance);
        Account.push_back(newAcc);
    }
    
    int findAccount(const std::string &name){
        for (int i = 0; i< Account.size(); ++i){
            if (Account[i].getOwnerName() == name){
                return i;
            }
        }
        return -1;
    }
    
    bool isValidName(std::string &Name){
        if (Name.empty()) return false;
        for
    }
    bool isValidBalance(std::double &Balance){}
    
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Banking System\n";
    BankAccount account;
    account.deposit(100);
    account.withdraw(40);
    std::cout<<"currect balance: "<<account.checkBalance()<<std::endl;
    
    std::string Name;
    std::cout<<"Enter name"<<std::endl;
    std::cin>>Name;
    
    double Balance;
    std::cout<<"Enter Balance amount"<<std::endl;
    std::cin>>Balance;
    
    Banksystem bank;
    bank.newAccount(Name,Balance);
    
    return 0;
}





/* ===============================
   C++ const Cheat Sheet
   ===============================

1. Function Parameters:
-----------------------
- Use const reference for large read-only inputs:
    void printName(const std::string &name);

2. Class Member Functions:
--------------------------
- Use const at the end if function doesn’t modify object:
    std::string getName() const;

3. Local Variables:
-------------------
- Use const to prevent changes:
    const int maxTries = 3;

4. Pointers:
------------
int* ptr;               // normal pointer
const int* ptr;         // pointer to const value (can't change *ptr)
int* const ptr;         // const pointer (can't change ptr)
const int* const ptr;   // const pointer to const value

================================ */

