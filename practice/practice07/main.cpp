//AI: Utilized to help organize my readEmployee function

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>

//Base class
class Employee {
private:
    std::string name;
    int id;
public:
    //Constructor
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

//Derived Classes
class SalariedEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(std::string name, int id, double salary) : Employee(name, id), monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Salary: $" << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string name, int id, double rate, int hours) : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() const override { return hourlyRate * hoursWorked; }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Hourly Rate: $" << hourlyRate << ", Hours Worked: " << hoursWorked
        << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
        : Employee(name, id), baseSalary(base), salesAmount(sales), commissionRate(rate){}
    double calculateSalary() const override { return baseSalary + (salesAmount * commissionRate); }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Base Salary: $" << baseSalary << ", Sales Amount: " << salesAmount
            << ", Commission Rate: $ " << commissionRate << ", Total Salary: $" << calculateSalary() << std::endl;
    }
};

//Function to read employees from file
bool readEmployees(std::vector<Employee*> &employees, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return false;
    }

    if (file.peek() == EOF) {
        std::cerr << "Error: File is empty!" << std::endl;
        return false;
    }

    std::string type;
    std::string name;
    int id;

    while (file >> type >> id) {
        file.ignore();
        std::getline(file, name, ' ');
        //checks for salaried type and then creates a new salaried employee and stores the info into the vector
        if (type == "Salaried") {
            double salary;
            file >> salary;
            employees.push_back(new SalariedEmployee(name, id, salary));
        } //same as above except checking for hourly 
        else if (type == "Hourly") {
            double rate;
            int hours;
            file >> rate >> hours;
            employees.push_back(new HourlyEmployee(name, id, rate, hours));
        } //same again but checking for commission
        else if (type == "Commission") {
            double base;
            double sales;
            double rate;
            file >> base >> sales >> rate;
            employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
        }
    }
    return true;
}

int main() {
    std::vector<Employee*> employees;
    readEmployees(employees, "employees.txt");

    for (const auto &employee : employees) {
        employee->displayInfo();
    }

    //free the allocated memory
    for (auto& employee : employees) {
        delete employee;
    }

    return 0;
    
}
