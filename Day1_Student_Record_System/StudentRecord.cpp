#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float marks;

public:
    void input() {
        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter marks (0-100): ";
        cin >> marks;
    }

    char grade() {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 40) return 'C';
        else return 'F';
    }

    void display() {
        cout << "Name : " << name << endl;
        cout << "Roll : " << roll << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade() << endl;
        cout << "----------------------\n";
    }

    float getMarks() { return marks; }
    string getName() { return name; }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];   
    float total = 0;
    int topperIndex = 0;

    // input students
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i+1 << endl;
        s[i].input();
    }

    // display students
    cout << "\nStudent Records\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    // average + topper
    for (int i = 0; i < n; i++) {
        total += s[i].getMarks();
        if (s[i].getMarks() > s[topperIndex].getMarks())
            topperIndex = i;
    }

    cout << "Class Average Marks: " << total / n << endl;
    cout << "Class Topper: " << s[topperIndex].getName() << endl;

    return 0;
}
