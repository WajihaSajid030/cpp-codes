#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
struct Student {
    int id;
    char name[50];
    float marks;
    char grade;
};
char computeGrade(float marks) {
    if (marks >= 85) return 'A';
    if (marks >= 70) return 'B';
    if (marks >= 50) return 'C';
    return 'F';
}
void addStudentToFile(const char* filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    cout << "Enter student ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter student name: ";
    cin.getline(s.name, 50);

    do {
        cout << "Enter marks (0-100): ";
        cin >> s.marks;
        if (s.marks < 0 || s.marks > 100) {
            cout << "Invalid marks! Must be between 0-100." << endl;
        }
    } while (s.marks < 0 || s.marks > 100);

    s.grade = computeGrade(s.marks);

    file << s.id << " | " << s.name << " | " << fixed << setprecision(1) << s.marks << " | " << s.grade << endl;
    file.close();
    cout << "Student added successfully!" << endl;
}
void displayStudentsFromFile(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    cout << "\nSTUDENT RECORDS\n";
    cout << "----------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "MARKS" << "GRADE" << endl;
    cout << "----------------------------------------\n";

    char line[200];
    while (file.getline(line, 200)) {
        char* parts[4];
        int i = 0;
        char* token = strtok(line, "|");
        while (token != NULL && i < 4) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            parts[i++] = token;
            token = strtok(NULL, "|");
        }

        if (i == 4) {
            cout << left << setw(10) << parts[0] 
                 << setw(20) << parts[1] 
                 << setw(10) << parts[2] 
                 << parts[3] << endl;
        }
    }
    file.close();
}
void searchStudentByID(const char* filename, int id) {
    ifstream file(filename);
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    bool found = false;
    char line[200];
    while (file.getline(line, 200)) {
        char* parts[4];
        int i = 0;
        
        char* token = strtok(line, "|");
        while (token != NULL && i < 4) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            parts[i++] = token;
            token = strtok(NULL, "|");
        }

        if (i == 4 && atoi(parts[0]) == id) {
            cout << "\nSTUDENT FOUND\n";
            cout << "----------------------------------------\n";
            cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "MARKS" << "GRADE" << endl;
            cout << "----------------------------------------\n";
            cout << left << setw(10) << parts[0] 
                 << setw(20) << parts[1] 
                 << setw(10) << parts[2] 
                 << parts[3] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found." << endl;
    }
    file.close();
}
void deleteStudentByID(const char* filename, int id) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "No records found!" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cout << "Error creating temporary file!" << endl;
        inFile.close();
        return;
    }

    bool found = false;
    char line[200];
    while (inFile.getline(line, 200)) {
        char temp[200];
        strcpy(temp, line);
        
        char* token = strtok(temp, "|");
        if (token) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            if (atoi(token) != id) {
                tempFile << line << endl;
            } else {
                found = true;
            }
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove(filename);
        rename("temp.txt", filename);
        cout << "Student with ID " << id << " deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Student with ID " << id << " not found." << endl;
    }
}
void showMenu() {
    cout << "\nSTUDENT GRADE MANAGEMENT SYSTEM\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Delete Student by ID\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    const char* filename = "students.txt";
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudentToFile(filename);
                break;
            case 2:
                displayStudentsFromFile(filename);
                break;
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                searchStudentByID(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                deleteStudentByID(filename, id);
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}