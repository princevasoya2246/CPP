#include<iostream>
#include<string.h>

using namespace std;

class Employee{
    private:
    string name;
    float salary;
    string designation;

    public:
    void setname(string name){
        this->name=name;
    }
    void setsalary(float salary){
        this->salary=salary;
    }
    void setdesignation(string designation){
        this->designation=designation;
    }
    string getname(){
        return name;
    }
    float getsalary(){
        return salary;
    }
    string getdesignation(){
        return designation;
    }
};
int main(){
    Employee e;
    string name;
    float salary;
    string desig;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter designation: ";
    cin >> desig;

    e.setname(name);
    e.setsalary(salary);
    e.setdesignation(desig);
    
    cout << "\nEmployee Name: " << e.getname() << endl;
    cout << "Employee Salary: " << e.getsalary() << endl;
    cout << "Employee Designation: " << e.getdesignation() << endl;

    return 0;
}