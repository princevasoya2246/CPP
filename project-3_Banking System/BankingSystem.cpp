#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class BankAccount{
    public:
    int accountNumber;
    string accountHolderName;
    double balance;

    BankAccount(int acc,string accname,double bal){
        this->accountNumber=acc;
        this->accountHolderName=accname;
        this->balance=bal;
    }

    void deposit(double amount){
        balance+=amount;
     }
    void withdraw(double amount){
         
        if (this->balance >= amount)
        {
            this->balance -= amount;
            cout << amount << " withdrawal Successfully" << endl;
            return;
        }
        cout << "Not Valid Amount" << endl;
    
     }
    double getBalance(){
        return this->balance;

     }
    void displayAccountInfo(){
        cout << "Acount Holder Name :" << this->accountHolderName << endl;
        cout << "Acount Number :" << this->accountNumber << endl;
        cout << "Acount Balance :" << getBalance() << endl;
        cout << endl << endl;
     }

};

class SavingAccount:public BankAccount{
    public:
    float interestRate;

    SavingAccount(int acc,string accname,double bal,float intr):BankAccount(acc,accname,bal){
        this->interestRate=intr;
    }

    void calculateInterest(){
        cout << this->getBalance() * interestRate << endl;
    }

};

class CurrentAccount:public BankAccount{
    public:
    double overdraftLimit=100000;

    CurrentAccount(int acc,string accname,double bal,double overfl):BankAccount(acc,accname,bal){
        this->overdraftLimit=overfl;
    }

    void checkOverdraft(){
        if (this->overdraftLimit > 0)
        {
            cout << "OverDraft Available !!" << endl;
            return;
        }
        cout << "Limit Exceed" << endl;

    }
    
};

class FixedDepositAccount:public BankAccount{
    public:
    int months;

    FixedDepositAccount(int acc,string accname,double bal,int m):BankAccount(acc,accname,bal){
        this->months=m;
    }

    void calculateInterest(){
        cout << this->getBalance() * (0.8 * this->months ) << endl; 

    }
};
int main(){


    return 0;
}



