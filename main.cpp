#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Student
{
public:
    string name, clss, email, password, PRNno;
    int rollno;

    void getDetails()
    {
        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter class: ";
        getline(cin, clss);

        cout << "Enter roll no: ";
        cin >> rollno;
        cin.ignore(1000, '\n');

        cout << "Enter PRN no: ";
        getline(cin, PRNno);

        cout << "Enter email: ";
        getline(cin, email);

        cout << "Enter password: ";
        password = "";
        char ch;

        while (true)
        {
            ch = _getch();

            if (ch == '\r')
                break;

            if (ch == '\b')
            {
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch >= 32 && ch <= 126)
            {
                password += ch;
                cout << '*';
            }
        }

        cout << "\n";
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nClass: " << clss;
        cout << "\nRoll No: " << rollno;
        cout << "\nPRN No: " << PRNno;
        cout << "\nEmail: " << email;
        cout << "\n";
    }

    void registerStudent()
    {
        ofstream file("students.txt", ios::app);

        if (!file)
        {
            cout << "Error opening file!\n";
            return;
        }

        file << name << "\n";
        file << clss << "\n";
        file << rollno << "\n";
        file << PRNno << "\n";
        file << email << "\n";
        file << password << "\n";
        file << "-------------------\n";

        file.close();

        cout << "\nStudent registered successfully!\n";
    }
    void loginStudent()
    {
        string inputPRN, inputPassword;
        string fileName, fileClass, filePRN, fileEmail, filePassword;
        int fileRoll;

        cout << "\n--- Student Login ---\n";

        cout << "Enter PRN No: ";
        getline(cin, inputPRN);

        cout << "Enter Password: ";
        inputPassword = "";
        char ch;

        while (true)
        {
            ch = _getch();

            if (ch == '\r')
                break;

            if (ch == '\b')
            {
                if (!inputPassword.empty())
                {
                    inputPassword.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch >= 32 && ch <= 126)
            {
                inputPassword += ch;
                cout << '*';
            }
        }

        cout << "\n";

        ifstream file("students.txt");

        if (!file)
        {
            cout << "Unable to open student database!\n";
            return;
        }

        while (getline(file, fileName))
        {
            getline(file, fileClass);

            file >> fileRoll;
            file.ignore(1000, '\n');

            getline(file, filePRN);
            getline(file, fileEmail);
            getline(file, filePassword);

            string separator;
            getline(file, separator);

            if (filePRN == inputPRN &&
                filePassword == inputPassword)
            {

                cout << "\nLogin Successful!\n";
                cout << "\nWelcome, " << fileName << "!\n";
                cout << "Class: " << fileClass << "\n";
                cout << "Roll No: " << fileRoll << "\n";
                cout << "PRN No: " << filePRN << "\n";
                cout << "Email: " << fileEmail << "\n";

                file.close();
                return;
            }
        }

        file.close();
        cout << "\nInvalid PRN number or password!\n";
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        cout << "\n===== STUDENT SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
            s.getDetails();
            s.registerStudent();
            break;

        case 2:
            s.loginStudent();
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
    return 0;
}
