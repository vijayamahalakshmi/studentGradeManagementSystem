#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student structure to hold individual records
struct Student {
    int rollNumber;
    string name;
    float marks;
    char grade;
};

// Function to calculate grade based on marks
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cout << "Enter Name: ";
    cin.ignore(); // to clear newline from buffer
    getline(cin, s.name);
    cout << "Enter Marks (out of 100): ";
    cin >> s.marks;
    s.grade = calculateGrade(s.marks);
    students.push_back(s);
    cout << "Student added successfully.\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    cout << "\nStudent Records:\n";
    cout << "-----------------------------------------------------\n";
    cout << "Roll No\tName\t\tMarks\tGrade\n";
    cout << "-----------------------------------------------------\n";

    for (const auto& s : students) {
        cout << s.rollNumber << "\t" << s.name << "\t\t" << s.marks << "\t" << s.grade << endl;
    }
    cout << "-----------------------------------------------------\n";
}

// Function to delete a student by roll number
void deleteStudent(vector<Student>& students) {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == roll) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student with Roll Number " << roll << " not found.\n";
}

// Main menu loop
int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Grade Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
