#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    virtual double calculateSalary() = 0; // pure virtual
    virtual void display() = 0;

    string getName() { return name; }

    virtual ~Employee() {}
};



// FULL TIME EMPLOYEE
class FullTime : public Employee {
    double monthlySalary;
    double bonusPercent;

public:
    FullTime(string n, int i, double salary, double bonus)
        : Employee(n, i) {
        monthlySalary = salary;
        bonusPercent = bonus;
    }

    double calculateSalary() override {
        return monthlySalary + (monthlySalary * bonusPercent / 100);
    }

    void display() override {
        cout << "FullTime Employee\n";
        cout << "Name: " << name << " | ID: " << id << endl;
        cout << "Salary (with bonus): " << calculateSalary() << "\n\n";
    }
};



// PART TIME EMPLOYEE
class PartTime : public Employee {
    double hourlyRate;
    int hoursWorked;

public:
    PartTime(string n, int i, double rate, int hours)
        : Employee(n, i) {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }

    void display() override {
        cout << "PartTime Employee\n";
        cout << "Name: " << name << " | ID: " << id << endl;
        cout << "Salary: " << calculateSalary() << "\n\n";
    }
};



int main() {
    vector<Employee*> employees;

    // Adding employees
    employees.push_back(new FullTime("Abhi", 101, 50000, 10));
    employees.push_back(new PartTime("Riya", 102, 500, 80));
    employees.push_back(new FullTime("Karan", 103, 60000, 15));
    employees.push_back(new PartTime("Sneha", 104, 400, 60));

    cout << "---- Salary Details ----\n\n";

    double maxSalary = 0;
    string highestPaid;

    for (auto emp : employees) {
        emp->display();

        double sal = emp->calculateSalary();
        if (sal > maxSalary) {
            maxSalary = sal;
            highestPaid = emp->getName();
        }
    }

    cout << "Highest Paid Employee: " << highestPaid
         << " (Salary: " << maxSalary << ")" << endl;

    // Free memory
    for (auto emp : employees)
        delete emp;

    return 0;
}
