#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    explicit Person(const string& n) : name(n) {}

    virtual void display() const {
        cout << "Name: " << name << '\n';
    }

    string getName() const {
        return name;
    }

    virtual ~Person() = default;
};

class Student : public Person {
private:
    int id;
    map<string, double> grades;

public:
    Student(int studentId, const string& studentName)
        : Person(studentName), id(studentId) {}

    int getId() const {
        return id;
    }

    void addGrade(const string& subject, double grade) {
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade. Enter 0-100.\n";
            return;
        }

        grades[subject] = grade;
        cout << "Grade added successfully.\n";
    }

    double average() const {
        if (grades.empty())
            return 0.0;

        double total = 0.0;
        for (const auto& entry : grades)
            total += entry.second;

        return total / grades.size();
    }

    char getGrade() const {
        double avg = average();

        if (avg >= 90) return 'A';
        if (avg >= 80) return 'B';
        if (avg >= 70) return 'C';
        if (avg >= 60) return 'D';
        return 'F';
    }

    void display() const override {
        cout << "\n-----------------------------\n";
        cout << "Student ID: " << id << '\n';
        cout << "Name: " << name << '\n';
        cout << "Subjects:\n";

        if (grades.empty()) {
            cout << "No grades available.\n";
        } else {
            for (const auto& entry : grades)
                cout << "  " << entry.first << ": " << entry.second << '\n';
        }

        cout << fixed << setprecision(2);
        cout << "Average: " << average() << '\n';
        cout << "Grade: " << getGrade() << '\n';
    }

    void save(ofstream& file) const {
        file << id << "|" << name << "|";
        for (const auto& entry : grades)
            file << entry.first << ":" << entry.second << ";";
        file << '\n';
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;

        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        if (findStudent(id) != nullptr) {
            cout << "Student ID already exists.\n";
            return;
        }

        students.emplace_back(id, name);
        cout << "Student added successfully.\n";
    }

    Student* findStudent(int id) {
        for (auto& student : students) {
            if (student.getId() == id)
                return &student;
        }
        return nullptr;
    }

    void addGrade() {
        int id;
        string subject;
        double grade;

        cout << "Enter student ID: ";
        cin >> id;

        Student* student = findStudent(id);
        if (student == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        cout << "Enter subject: ";
        cin >> subject;

        cout << "Enter grade: ";
        cin >> grade;

        student->addGrade(subject, grade);
    }

    void searchStudent() {
        int id;

        cout << "Enter student ID: ";
        cin >> id;

        Student* student = findStudent(id);
        if (student == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        student->display();
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (const auto& student : students)
            student.display();
    }

    void saveToFile() const {
        ofstream file("students.txt");

        if (!file) {
            cout << "Unable to open students.txt.\n";
            return;
        }

        for (const auto& student : students)
            student.save(file);

        cout << "Data saved successfully.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n================================\n";
        cout << " STUDENT GRADE MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Student\n";
        cout << "2. Add Grade\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Save Data\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.addGrade();
                break;
            case 3:
                manager.searchStudent();
                break;
            case 4:
                manager.displayAll();
                break;
            case 5:
                manager.saveToFile();
                break;
            case 6:
                manager.saveToFile();
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
