#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string accountHolderName;
    double balance;
    static int noOfAccount;

    BankAccount(int acc, string accname, double bal)
    {
        this->accountNumber = acc;
        this->accountHolderName = accname;
        this->balance = bal;
        noOfAccount++;
    }

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {

        if (this->balance >= amount)
        {
            this->balance -= amount;
            // cout << amount << " withdrawal Successfully" << endl;
            return;
        }
        cout << "Not Valid Amount" << endl;
    }
    double getBalance()
    {
        return this->balance;
    }
    void displayAccountInfo()
    {
        cout << "Acount Holder Name :" << this->accountHolderName << endl;
        cout << "Acount Number :" << this->accountNumber << endl;
        cout << "Acount Balance :" << getBalance() << endl;
        cout << endl
             << endl;
    }
    // void numofbankA(){
    //     cout << "no.of bank accounyt :- " << noOfAccount << endl;
    // }
};

class SavingAccount : public BankAccount
{
public:
    float interestRate;
    static int noOfSAccount;

    SavingAccount(int acc, string accname, double bal, float intr) : BankAccount(acc, accname, bal)
    {
        this->interestRate = intr;
        noOfSAccount++;
    }

    void calculateInterest()
    {

        cout << "Your intrest is a : " << (this->getBalance() * interestRate) / 100 << endl;
    }
};

class CurrentAccount : public BankAccount
{
public:
    double overdraftLimit;
    static int noOfCAccount;

    CurrentAccount(int acc, string accname, double bal, double overfl) : BankAccount(acc, accname, bal)
    {
        this->overdraftLimit = overfl;
        noOfCAccount++;
    }

    void checkOverdraft()
    {
        if (this->overdraftLimit > 0)
        {
            cout << "OverDraft Available !!" << endl;
            cout << "limit is : " << this->overdraftLimit;
            return;
        }
        cout << "Limit Exceed" << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    int months;
    static int noOfFAccount;

    FixedDepositAccount(int acc, string accname, double bal, int m) : BankAccount(acc, accname, bal)
    {
        this->months = m;
        noOfFAccount++;
    }

    void calculateInterest()
    {
        cout << "your intrest is a : " << (this->getBalance() * (0.8 * this->months)) / 100 << endl;
    }
};

int BankAccount::noOfAccount = 0;
int SavingAccount::noOfSAccount = 0;
int CurrentAccount::noOfCAccount = 0;
int FixedDepositAccount::noOfFAccount = 0;

int main()
{
    // int choice;
    SavingAccount *s[100];
    SavingAccount s1(1234, "Rajveer", 20000, 7);
    s[SavingAccount::noOfSAccount - 1] = &s1;
    SavingAccount s2(1235, "Rahul", 6000, 7);
    s[SavingAccount::noOfSAccount - 1] = &s2;
    SavingAccount s3(1236, "jevin", 8000, 7);
    s[SavingAccount::noOfSAccount - 1] = &s3;

    CurrentAccount *c[100];
    CurrentAccount c1(1010, "rashik", 15000, 50000);
    c[CurrentAccount::noOfCAccount - 1] = &c1;
    CurrentAccount c2(1011, "krish", 19000, 60000);
    c[CurrentAccount::noOfCAccount - 1] = &c2;
    CurrentAccount c3(1012, "tirth", 50000, 40000);
    c[CurrentAccount::noOfCAccount - 1] = &c3;

    FixedDepositAccount *f[100];
    FixedDepositAccount f1(1210, "yash", 20000, 5);
    f[FixedDepositAccount::noOfFAccount - 1] = &f1;
    FixedDepositAccount f2(1211, "meet", 25000, 8);
    f[FixedDepositAccount::noOfFAccount - 1] = &f2;
    FixedDepositAccount f3(1212, "fenil", 30000, 9);
    f[FixedDepositAccount::noOfFAccount - 1] = &f3;

    int choice;
    while (1)
    {
        cout << "\n\n1.Number of bank account " << endl;
        cout << "2.Display all account details  " << endl;
        cout << "3.deposite " << endl;
        cout << "4.withdraw " << endl;
        cout << "5.check balance " << endl;
        cout << "6.saving account intrestrate" << endl;
        cout << "7.overeflow check " << endl;
        cout << "8.fixeddeposite account intrestrate" << endl;
        cout << "0.Exit " << endl;

        cout << "\nEnter choice : ";
        cin >> choice;
        int accn;
        double amnt;

        switch (choice)
        {
        case 1:
            cout << endl
                 << "total number of account :" << BankAccount::noOfAccount << endl
                 << endl;
            cout << endl
                 << "total number of saving account :" << SavingAccount::noOfSAccount << endl
                 << endl;
            cout << endl
                 << "total number of current account :" << CurrentAccount::noOfCAccount << endl
                 << endl;
            cout << endl
                 << "total number of fixed-deposite  account :" << FixedDepositAccount::noOfFAccount << endl
                 << endl;

            break;
        case 2:
            cout << "1.Display all  saving-acc " << endl;

            for (int i = 0; i < 3; i++)
            {
                s[i]->displayAccountInfo();
            }
            cout << "2.Display all  current-acc " << endl;

            for (int i = 0; i < 3; i++)
            {
                c[i]->displayAccountInfo();
            }
            cout << "3.Display all  fixeddeposite-acc " << endl;

            for (int i = 0; i < 3; i++)
            {
                f[i]->displayAccountInfo();
            }
            break;
        case 3:
            int ch;

            cout << "\n1. saving account" << endl;
            cout << "2. current account " << endl;
            cout << "3. fixed deposite account" << endl;
            cout << "\n Enter account type : ";
            cin >> ch;
            // int accn;
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            // double amnt;
            switch (ch)
            {
            case 1:

                for (int i = 0; i < SavingAccount::noOfSAccount; i++)
                {
                    if (accn == s[i]->accountNumber)
                    {
                        cout << "Enter deposite amount : ";
                        cin >> amnt;
                        s[i]->deposit(amnt);
                        cout << "deposite successfull";
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::noOfCAccount; i++)
                {
                    if (accn == c[i]->accountNumber)
                    {
                        cout << "Enter deposite amount : ";
                        cin >> amnt;
                        c[i]->deposit(amnt);
                        cout << "deposite successfull";
                    }
                }
                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::noOfFAccount; i++)
                {
                    if (accn == f[i]->accountNumber)
                    {
                        cout << "Enter deposite amount : ";
                        cin >> amnt;
                        f[i]->deposit(amnt);
                        cout << "deposite successfull";
                    }
                }
                break;

            default:
                cout << "Enter valid choice";
                break;
            }

            break;
        case 4:
            int ch1;

            cout << "\n1. saving account" << endl;
            cout << "2. current account " << endl;
            cout << "3. fixed deposite account" << endl;
            cout << "\n Enter account type : ";
            cin >> ch1;
            // int accn;
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            // double amnt;
            switch (ch1)
            {
            case 1:

                for (int i = 0; i < SavingAccount::noOfSAccount; i++)
                {
                    if (accn == s[i]->accountNumber)
                    {
                        cout << "Enter withdraw amount : ";
                        cin >> amnt;
                        if (amnt <= s[i]->balance)
                        {
                            s[i]->withdraw(amnt);
                            cout << "========withdraw successfull==========";
                        }
                        else
                        {
                            cout << "Not Valid Amount" << endl;
                        }
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::noOfCAccount; i++)
                {
                    if (accn == c[i]->accountNumber)
                    {
                        cout << "Enter withdraw amount : ";
                        cin >> amnt;
                        if (amnt <= s[i]->balance)
                        {
                            c[i]->withdraw(amnt);
                            cout << "==========withdraw successfull=======";
                        }
                        else
                        {
                            cout << "Not Valid Amount" << endl;
                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::noOfFAccount; i++)
                {
                    if (accn == f[i]->accountNumber)
                    {
                        cout << "Enter withdraw amount : ";
                        cin >> amnt;
                        if (amnt <= s[i]->balance)
                        {
                            f[i]->withdraw(amnt);
                            cout << "========withdraw successfull========";
                        }
                        else
                        {
                            cout << "Not Valid Amount" << endl;
                        }
                    }
                }
                break;

            default:
                cout << "Enter valid choice";
                break;
            }

            break;
        case 5:
            int ch2;

            cout << "\n1. saving account" << endl;
            cout << "2. current account " << endl;
            cout << "3. fixed deposite account" << endl;
            cout << "\n Enter account type : ";
            cin >> ch2;
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            switch (ch2)
            {
            case 1:

                for (int i = 0; i < SavingAccount::noOfSAccount; i++)
                {
                    if (accn == s[i]->accountNumber)
                    {
                        cout << "Your  balance is a: " << s[i]->getBalance() << endl;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::noOfCAccount; i++)
                {
                    if (accn == c[i]->accountNumber)
                    {
                        cout << "balance is a: " << c[i]->getBalance() << endl;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::noOfFAccount; i++)
                {
                    if (accn == f[i]->accountNumber)
                    {
                        cout << "balance is a: " << f[i]->getBalance() << endl;
                    }
                }
                break;
            default:
                cout << "Enter valid choice";
                break;
            }
            break;

        case 6:
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            for (int i = 0; i < SavingAccount::noOfSAccount; i++)
            {
                if (accn == s[i]->accountNumber)
                {
                    s[i]->calculateInterest();
                }
            }

            break;
        case 7:
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            for (int i = 0; i < CurrentAccount::noOfCAccount; i++)
            {
                if (accn == c[i]->accountNumber)
                {
                    c[i]->checkOverdraft();
                }
            }

            break;
        case 8:
            cout << "\n"
                 << "Enter account number : ";
            cin >> accn;
            for (int i = 0; i < FixedDepositAccount::noOfFAccount; i++)
            {
                if (accn == f[i]->accountNumber)
                {
                    f[i]->calculateInterest();
                }
            }
            break;
        case 0:
            exit(0);

            break;

        default:
            "------Enter a invalid choice---------";
            break;
        }
    }

    return 0;
}
