#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ----------------------
// Employee Class
// ----------------------
class Employee {
private:
    int employeeID;
    string name;
    double salary;
    string department;

public:
    // Constructor to initialize employee details
    Employee(int id, string name, double salary, string department)
        : employeeID(id), name(name), salary(salary), department(department) {}

    // Getter methods
    int getID() const { return employeeID; }
    string getName() const { return name; }
    double getSalary() const { return salary; }
    string getDepartment() const { return department; }

    // Setter methods
    void setSalary(double newSalary) { salary = newSalary; }
    void setDepartment(string newDepartment) { department = newDepartment; }

    // Method to calculate net salary after 10% tax deduction
    double getNetSalary() const {
        return salary - (salary * 0.10); // 10% tax
    }

    // Method to display employee details
    void display() const {
        cout << fixed << setprecision(2);  // Format salary output to 2 decimal places
        cout << "ID: " << employeeID
             << ", Name: " << name
             << ", Salary: $" << salary
             << ", Department: " << department
             << ", Net Salary (after 10% tax): $" << getNetSalary() << endl;
    }
};

// Vector to store the list of employees (in-memory list)
vector<Employee> employees;

// Function declarations
void addEmployee();
void viewEmployees();
void updateEmployee();
void deleteEmployee();

// ----------------------
// Main Program Loop
// ----------------------
int main() {
    int choice;

    // Infinite loop to keep the menu running until user exits
    while (true) {
        // Display menu options
        cout << "\n=== Employee Management System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user's choice
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: 
                cout << "Exiting program. Goodbye!\n"; 
                return 0;
            default: 
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// ----------------------
// Function to Add Employee
// ----------------------
void addEmployee() {
    int id;
    string name;
    double salary;
    string dept;

    // Collect employee data from user
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore(); // Clear newline from input buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Salary: ";
    cin >> salary;
    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, dept);

    // Add new employee to the vector
    employees.push_back(Employee(id, name, salary, dept));
    cout << "Employee added successfully.\n";
}

// ----------------------
// Function to View All Employees
// ----------------------
void viewEmployees() {
    // Check if list is empty
    if (employees.empty()) {
        cout << "No employees to display.\n";
        return;
    }

    // Display each employee's information
    for (const auto& emp : employees) {
        emp.display();
    }
}

// ----------------------
// Function to Update Employee Details
// ----------------------
void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    bool found = false;

    // Search for employee by ID
    for (auto& emp : employees) {
        if (emp.getID() == id) {
            found = true;

            // Ask what to update
            int choice;
            cout << "1. Update Salary\n2. Update Department\nEnter choice: ";
            cin >> choice;
            cin.ignore();  // Clear buffer

            if (choice == 1) {
                double newSalary;
                cout << "Enter new salary: ";
                cin >> newSalary;
                emp.setSalary(newSalary);
                cout << "Salary updated.\n";
            } else if (choice == 2) {
                string newDept;
                cout << "Enter new department: ";
                getline(cin, newDept);
                emp.setDepartment(newDept);
                cout << "Department updated.\n";
            } else {
                cout << "Invalid choice.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "Employee not found.\n";
    }
}

// ----------------------
// Function to Delete an Employee
// ----------------------
void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    // Search and delete by ID
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getID() == id) {
            employees.erase(it);
            cout << "Employee deleted.\n";
            return;
        }
    }

    cout << "Employee not found.\n";
}
