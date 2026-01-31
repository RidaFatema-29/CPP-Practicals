//Write a menu driven C++ program to store set operations for event participation.
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string code[10], project[10], master[10], paper[10];
    int s1, s2, s3, s4;

    // Helper: check if name exists in array
    bool exists(string arr[], int size, string name) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == name) return true;
        }
        return false;
    }

    void getdata() {
        cout << "\nEnter number of students in coding contest: ";
        cin >> s1;
        cout << "Enter names: ";
        for (int i = 0; i < s1; i++) cin >> code[i];

        cout << "\nEnter number of students in project competition: ";
        cin >> s2;
        cout << "Enter names: ";
        for (int j = 0; j < s2; j++) cin >> project[j];

        cout << "\nEnter number of students in mastermind: ";
        cin >> s3;
        cout << "Enter names: ";
        for (int k = 0; k < s3; k++) cin >> master[k];

        cout << "\nEnter number of students in paper presentation: ";
        cin >> s4;
        cout << "Enter names: ";
        for (int m = 0; m < s4; m++) cin >> paper[m];
    }

    // Students in both coding and project
    void second() {
        cout << "\nBoth coding and project: ";
        for (int i = 0; i < s1; i++) {
            if (exists(project, s2, code[i])) {
                cout << code[i] << " ";
            }
        }
        cout << "\n";
    }

    // Students in coding or project
    void third() {
        cout << "\nCoding or project: ";
        // print coding students first
        for (int i = 0; i < s1; i++) cout << code[i] << " ";

        // print only those project students not in coding
        for (int j = 0; j < s2; j++) {
            if (!exists(code, s1, project[j])) {
                cout << project[j] << " ";
            }
        }
        cout << "\n";
    }

    // Students in coding but not mastermind
    void fourth() {
        cout << "\nCoding but not mastermind: ";
        for (int i = 0; i < s1; i++) {
            if (!exists(master, s3, code[i])) {
                cout << code[i] << " ";
            }
        }
        cout << "\n";
    }

    // Students in all events
    void getall() {
        cout << "\nAll events: ";
        for (int i = 0; i < s1; i++) {
            if (exists(project, s2, code[i]) &&
                exists(master, s3, code[i]) &&
                exists(paper, s4, code[i])) {
                cout << code[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Student std;
    int choice;
    cout << "Students participating in EVENT EQUINOX\n";
    std.getdata();
    do {
        cout << "\n--- MENU ---";
        cout << "\n 1. Students in both coding and project";
        cout << "\n 2. Students in coding or project";
        cout << "\n 3. Students in coding but not mastermind";
        cout << "\n 4. Students in all events";
        cout << "\n 5. Exit";
        cout << "\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: std.second(); break;
            case 2: std.third(); break;
            case 3: std.fourth(); break;
            case 4: std.getall(); break;
            case 5: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice\n"; break;
        }
    } while (choice != 5);
    return 0;
}