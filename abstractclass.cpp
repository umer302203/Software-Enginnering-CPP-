#include <iostream>
using namespace std;

// Abstract class
class Employee {
public:
    virtual void calculateSalary() = 0; // pure virtual function
};

class Manager : public Employee {
private:
    float fixedSalary, bonus;
public:
    Manager(float s, float b) : fixedSalary(s), bonus(b) {}
    void calculateSalary() override {
        cout << "Manager's Salary = " << (fixedSalary + bonus) << endl;
    }
};

class Developer : public Employee {
private:
    float fixedSalary, overtimePay;
public:
    Developer(float s, float o) : fixedSalary(s), overtimePay(o) {}
    void calculateSalary() override {
        cout << "Developer's Salary = " << (fixedSalary + overtimePay) << endl;
    }
};

int main() {
    Employee* emp;

    Manager m(50000, 10000);
    Developer d(40000, 8000);

    emp = &m;
    emp->calculateSalary();

    emp = &d;
    emp->calculateSalary();

    return 0;
}
